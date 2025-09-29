

#include <unistd.h>


size_t	uf_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len = len + 1;
	return (len);
}

int	main(int ac, const char **av) {
	if (ac > 1) {
		write(1, av[ac - 1], uf_strlen(av[ac - 1]));
	}
	write(1, "\n", 1);
	return (0);
}
