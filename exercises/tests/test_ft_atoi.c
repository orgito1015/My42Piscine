#include <unistd.h>
#include <stdio.h>

int	ft_atoi(const char *str);

int		main(int ac, char **av)
{
    if (ac == 2) {
		printf("%d", ft_atoi(av[1]));
	}
    else
    {
        write(1, "\n", 1);
    }
	return (0);
}
