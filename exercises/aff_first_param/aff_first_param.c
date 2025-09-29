#include <unistd.h>

int ft_strlen(char* s)
{
	int i;

	for (i = 0; s[i]; i++)
		;
	return i;
}

int main(int ac, char** av)
{
	if (ac >= 2)
		write(1, av[1], ft_strlen(av[1]));
	write(1, "\n", 1);
	return (0);
}
