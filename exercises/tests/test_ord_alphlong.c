#include <stdlib.h>
#include <unistd.h>

int		count_words(char *str, int len)
{
	int i;
	int pos;
	int n_words;

	n_words = 0;
	pos = -1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (i - pos - 1 == len)
				n_words++;
			pos = i;
		}
		i++;
	}
	if (i - pos - 1 == len)
		n_words++;
	return (n_words);
}

int		max_word_length(char *str)
{
	int i;
	int pos;
	int max_word_length;

	pos = -1;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (i - pos - 1 > max_word_length)
				max_word_length = i - pos - 1;
			pos = i;
		}
		i++;
	}
	if (i - pos - 1 > max_word_length)
		max_word_length = i - pos - 1;
	return (max_word_length);
}

char	*ft_strndup(char *str, int n)
{
	char	*result;
	int		i;

	result = (char*)malloc(sizeof(char) * (n + 1));
	i = 0;
	while (i < n)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

void	ft_putstr(char *str)
{
	int len;

	len = 0;
	while (str[len] != 0)
		len++;
	write(1, str, len);
}

char	to_lowercase(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

int		ft_strcmpi(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (to_lowercase(s1[i]) != to_lowercase(s2[i]))
			return (to_lowercase(s2[i]) - to_lowercase(s1[i]));
		i++;
	}
	return (to_lowercase(s2[i]) - to_lowercase(s1[i]));
}

void	sort_and_print(char **tab, int n)
{
	int		i;
	int		first;
	int		sorted;
	char	*s;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 1;
		while (i < n)
		{
			if (ft_strcmpi(tab[i - 1], tab[i]) < 0)
			{
				s = tab[i];
				tab[i] = tab[i - 1];
				tab[i - 1] = s;
				sorted = 0;
			}
			i++;
		}
	}
	first = 1;
	i = -1;
	while (++i < n)
	{
		if (!first)
			ft_putstr(" ");
		ft_putstr(tab[i]);
		first = 0;
	}
}

void	print_words(char *str, int len, int n)
{
	char	**tab;
	int		pos;
	int		i;
	int		n_word;

	tab = (char**)malloc(sizeof(char*) * n);
	if (!tab)
		return ;
	pos = -1;
	n_word = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			if (i - pos - 1 == len)
				tab[n_word++] = ft_strndup(&(str[pos + 1]), i - pos - 1);
			pos = i;
		}
		i++;
	}
	if (i - pos - 1 == len)
		tab[n_word++] = ft_strndup(&(str[pos + 1]), i - pos - 1);
	sort_and_print(tab, n);
	i = 0;
	while (i < n)
		if (tab[i++])
			free(tab[i - 1]);
	free(tab);
}

void	ord_alphlong(char *str)
{
	int len;
	int imax;
	int n;

	imax = max_word_length(str);
	len = 1;
	while (len <= imax)
	{
		n = count_words(str, len);
		if (n > 0)
		{
			print_words(str, len, n);
			ft_putstr("\n");
		}
		len++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ord_alphlong(argv[1]);
	else
		ft_putstr("\n");
	return (0);
}
