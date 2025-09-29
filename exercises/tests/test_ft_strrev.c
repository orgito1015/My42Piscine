#include <stdio.h>
char	*ft_strrev(char *str);

int	main(int ac, char **av)
{
	char *tmp;

	(void)ac;
	tmp = ft_strrev(av[1]);
	if (tmp != av[1])
		printf("wrong return\n");
	printf("%s", av[1]);
	return (0);
}

