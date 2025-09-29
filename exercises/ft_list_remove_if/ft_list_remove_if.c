#include	<stdlib.h>
#include	<string.h>

#include "ft_list.h"
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(void *, void *))
{
	if (begin_list == NULL || cmp == NULL)
		return ;
	t_list	*previous = *begin_list;
	t_list	*current = *begin_list;

	while (current)
	{
        if (current != NULL && cmp(current->data, data_ref) == 0)
		{
			if (current == (*begin_list))
			{
				*begin_list = current->next;
			}
			else
			{
				previous->next = current->next;
			}
            t_list* tmp = current->next;
			free(current);
            current = tmp;
            continue;
		}
		previous = current;
		current = current->next;
	}
}

