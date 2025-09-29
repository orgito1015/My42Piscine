#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef  char ft_bool;

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
  t_list* new_elem = malloc(sizeof(*new_elem));
	
  if (new_elem) {
    new_elem->data = data;
    new_elem->next = NULL;
  }
  return (new_elem);
}

void 	ft_list_remove_if(t_list **begin, void *data_ref, int (*cmp)(void *, void *));

void* ft_get_data(t_list *elem)
{
	if (elem)
		return elem->data;
	return NULL;
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem = ft_create_elem(data);
	t_list	*list = *begin_list;

	if ((*begin_list) == NULL) {
		(*begin_list) = new_elem;
	}
	else {
		for (;list->next != NULL; list = list->next);
		list->next = new_elem;
	}
}


void	print_list(t_list* list)
{
	for (;list;list = list->next)
	{
		printf("=> %s\n", (char *)list->data);
	}
}

int     main(int ac, char **av)
{
  	t_list	*list = NULL;
  	int		i;

	--ac;
  	++av;
    for (i = 0; i < ac; i++)
    {
    	ft_list_push_back(&list, av[i]);
    }
	ft_list_remove_if(&list, "none", (int (*)(void *, void *))strcmp);
	print_list(list);
    for (i = 0; i < ac; i += 2)
    {
		ft_list_remove_if(&list, av[i], (int (*)(void *, void *))strcmp);
    }
	printf("==========\n");
	print_list(list);
	printf("==========\n");
	return (0);
}
