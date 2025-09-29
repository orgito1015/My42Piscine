#include "../ft_list.h"
#include <stdlib.h>

t_list	*ft_list_push_back(t_list *begin, void *data)
{
	t_list	*new;
	t_list	*current;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	if (!begin)
		return (new);
	current = begin;
	while (current->next)
		current = current->next;
	current->next = new;
	return (begin);
}
