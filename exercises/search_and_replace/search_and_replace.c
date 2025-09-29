/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azrael <azrael@staff.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0000/00/00 00:00:00 by azrael            #+#    #+#             */
/*   Updated: 2016/01/15 10:14:25 by noich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      ft_putchar(str[i]);
      i++;
    }
}

char *cherche_remplace(char c, char r, char * s)
{
	int i;
	for (i=0;s[i]!='\0';++i)
		if (s[i]==c)
			s[i]=r;
	return(s);
}

int main(int ac, char **av)
{
	char *str;
	char *str1;
	char r;
	char s;
	if (ac != 4)
	{
	  ft_putstr("\n");
	  exit(0);
	}
	else if (ft_strlen(av[3]) != 1 || ft_strlen(av[2]) != 1)
	{
		ft_putstr("\n");
	    exit(0);
	}
	else
	{	
		r = av[3][0];
		s = av[2][0];
		str = av[1];
		str1 = cherche_remplace(s, r, str);
		ft_putstr(str1);
		ft_putstr("\n");
	}
	return (0);
}
