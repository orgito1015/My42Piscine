#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int nbr);

int	main(int ac, char **av)
{
	if (ac == 2)
		printf("%s", ft_itoa(atoi(av[1])));
	else
		printf("\n");
	return (0);
}
