#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_swap(int *a, int *b);

int	main(int ac, char **av)
{
	int	a;
	int	b;

	(void)ac;
	a = atoi(av[1]);
	b = atoi(av[2]);
	ft_swap(&a, &b);
	printf("%d %d", a, b);
	return (0);
}

