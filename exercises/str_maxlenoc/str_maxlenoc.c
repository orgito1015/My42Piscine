#include <unistd.h>
#include <stdio.h>

static int		ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && s1[i] && s1[i] == s2[i])
		i++;
	if (i == size || s1[i] == s2[i])
		return (1);
	return (0);
}

static int	ft_contains(char *s1, int size, char *s2)
{
	int i;
	int	len;
	

	len = 0;
	while (s2[len])
		len++;
	i = 0;
	while (i + size <= len)
	{
		if (ft_strncmp(s1, s2 + i, size))
			return (1);
		i = i + 1;
	}
	return (0);
}

static int	search_ft_contains(char *s1, int size, int argc, char **other)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_contains(s1, size, other[i]))
			break;
		i = i + 1;
	}
	if (i == argc)
	{
		write(1, s1, size);
		return 1;
	}
	return (0);
}

static void	maxlenoc(char *first, int argc, char **other, int len)
{
	int size;
	int	start;

	size = len;
	while (size > 0)
	{
		start = 0;
		while (start + size <= len)
		{
			if (search_ft_contains(first + start, size, argc, other))
				return ;
			start = start + 1;
		}
		size = size - 1;
	}
}

int	main(int argc, char **argv)
{
	int	len;

	if (argc > 1)
	{
		len = 0;
		while (argv[1][len])
			len++;
		maxlenoc(argv[1], argc - 2, argv + 2, len);
	}
	write(1, "\n", 1);
	return (0);
}
