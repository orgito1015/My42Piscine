#include <string.h>
#include <unistd.h>
#include <stdio.h>

char**	ft_split(char*);

void	display_tab(char **tab)
{
	int	i = 0;
	
	while (tab[i])
	{
		printf("%s : %zu\n", tab[i], strlen(tab[i]));
		i++;
	}
}

int	main(int ac, char **av)
{
	char		**tab;

	(void)ac;
	tab = ft_split(av[1]);
	display_tab(tab);
	return (0);
}

