#include "../ft_list.h"
#include <stdio.h>

void	ft_print_int_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		printf("%d\n", *(int *)current->data);
		current = current->next;
	}
} 

void	ft_print_str_list(t_list *list)
{
	t_list	*current;

	current = list;
	while (current)
	{
		printf("%s\n", (char *)current->data);
		current = current->next;
	}
} 