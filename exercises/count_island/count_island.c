/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 12:17:51 by exam              #+#    #+#             */
/*   Updated: 2017/03/31 13:19:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "count_island.h"

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	write(1, str, len);
}

int		line_length(char *line)
{
	int len;

	len = 0;
	while(line[len] != '\n')
		len++;
	return(len);
}

int		read_line(int fd, char buf[1024])
{
	int ret;
	char c;
	int i;

	i = 0;
	while ((ret = read(fd, &c, 1)))
	{
		buf[i++] = c;
		if (c == '\n')
			return (1);
	}
	return (0);
}

void	linecpy(char *dest_line, char src_line[1024])
{
	int i;

	i = 0;
	while (src_line[i] != '\n' && i < 1024)
	{
		dest_line[i] = src_line[i];
		i++;
	}
	dest_line[i] = src_line[i];
}

int		check_line(char line[1024])
{
	int i;

	i = 0;
	while(line[i] != '\n' && i < 1024)
	{
		if (line[i] != '.' && line[i] != 'X')
			return (0);
		i++;
	}
	return (1);
}

void	add_line(t_lines **lines, char line[1024], int len)
{
	t_lines *element;
	t_lines *new_line;

	new_line = (t_lines*)malloc(sizeof(t_lines));
	if (new_line)
	{
		new_line->next = NULL;
		new_line->len = len;
		new_line->c = (char*)malloc(sizeof(char) * (len + 1));
		if (new_line->c)
			linecpy(new_line->c, line);
		if (*lines == NULL)
			*lines = new_line;
		else
		{
			element = *lines;
			while (element->next != NULL)
				element = element->next;
			element->next = new_line;
		}
	}
}

void	print_lines(t_lines *lines)
{
	while (lines != NULL)
	{
		write(1, lines->c, lines->len + 1);
		lines = lines->next;
	}
}

void	clear_lines(t_lines **lines)
{
	t_lines *element;
	t_lines *next;
	
	element = *lines;
	while(element != NULL)
	{
		next = element->next;
		if (element->c)
			free(element->c);
		free(element);
		element = next;
	}
	*lines = NULL;
}

char	get_char_at(t_lines *lines, int i, int j)
{
	int line;

	line = 0;
	while (line < i)
	{
		lines = lines->next;
		if (lines == NULL)
			return ('.');
		line++;
	}
	return (lines->c[j]);
}

void	set_char_at(t_lines *lines, int i, int j, char value)
{
	int line;

	line = 0;
	while (line < i)
	{
		lines = lines->next;
		if (lines == NULL)
			return ;
		line++;
	}
	lines->c[j] = value;
}

void	paint_island(t_lines *lines, int width, int height, int i, int j, int i_island)
{
	char c_island;

	c_island = '0' + i_island;
	set_char_at(lines, i, j, c_island);
	if (j > 0 && get_char_at(lines, i, j - 1) == 'X')
		paint_island(lines, width, height, i, j - 1, i_island);
	if (j < width - 1 && get_char_at(lines, i, j + 1) == 'X')
		paint_island(lines, width, height, i, j + 1, i_island);
	if (i > 0 && get_char_at(lines, i - 1, j) == 'X')
		paint_island(lines, width, height, i - 1, j, i_island);
	if (i < height - 1 && get_char_at(lines, i + 1, j) == 'X')
		paint_island(lines, width, height, i + 1, j, i_island);
}

void	paint_islands(t_lines *lines, int width, int height)
{
	int i;
	int j;
	char c;
	int i_island;

	i_island = 0;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			c = get_char_at(lines, i, j);
			if (c == 'X')
				paint_island(lines, width, height, i, j, i_island++);
			j++;
		}
		i++;
	}
}

int		count_island(int fd)
{
	char line[1024];
	int first;
	int length;
	int prev_length;
	t_lines *lines;
	int fail;
	int height;

	lines = NULL;
	prev_length = -1;
	first = 1;
	height = 0;
	fail = 0;
	while(read_line(fd, line))
	{
		length = line_length(line);
		if ((!first && length != prev_length) || !check_line(line))
		{
			fail = 1;
			break;
		}
		add_line(&lines, line, length);
		height++;
		prev_length = length;
		first = 0;
	}
	if (!fail)
	{
		paint_islands(lines, length, height);
		print_lines(lines);
	}
	clear_lines(&lines);
	return (!fail);
}

int		main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		ft_putstr("\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_putstr("\n");
		else
			if (!count_island(fd))
				ft_putstr("\n");
	}	
	return (0);
}
