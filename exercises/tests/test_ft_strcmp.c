#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strcmp(char *s1, char *s2);

int	main(int ac, char **av)
{
	int i;

	if (ac != 3) {
		printf("\n");
		return (0);
	}
	i = ft_strcmp(av[1], av[2]);
	if (i == 0)
		printf("0");
	if (i > 0)
		printf("1");
	if (i < 0)
		printf("-1");
	return (0);
}

