#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end);

static void print_int_tab(int *tab, int size)
{
	int	i;

	for (i = 0; i < size; i++)
		printf("%d\n", tab[i]);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int size;
		if (atoi(av[2]) > atoi(av[1]))
			size = atoi(av[2]) - atoi(av[1]) + 1;
		else
			size = atoi(av[1]) - atoi(av[2]) + 1;
		print_int_tab(ft_range(atoi(av[1]), atoi(av[2])), size);
	}
	return (0);
}

