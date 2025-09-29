#include "ft_list.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int ft_list_size(t_list *begin_list);

t_list	*ft_list_push_front(t_list *begin, void *data)
{
	t_list*		new;
	
	new = malloc(sizeof(*new));
	new->next = begin;
	new->data = data;
	return new;
}
//THIS IS LINK TO GENERATOR.PY x2 just in case
#define MAX_ARGS (17 * 2)  

int	main(int ac, char **av)
{
    t_list	*list = NULL;
	char	*tab[MAX_ARGS];
	int		i;

    i = 0;
    while (i < ac)
    {
        tab[i] = av[i + 1];
        i++;
    }
    tab[i] = NULL;

    for (i = 1; i < ac; i++)
    {
  	    list = ft_list_push_front(list, tab[i]);
    }
    printf("%d", ft_list_size(list));
    return (0);
}
