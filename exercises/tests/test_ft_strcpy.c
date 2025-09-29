#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char*	ft_strcpy(char* dest, char* src);

int	main(int ac, char **av)
{
	char tab[] = "akjasdagsdkdgaskjadsjk if you read that, it means you didn't copy the \\0";
	char *str;
	if (ac == 2)
	{
		str = ft_strcpy(tab, av[1]);
		if (str != tab)
			printf("You didnt send the right return value\n");
		else
			printf("%s\n", tab);
	}
	return (0);
}

