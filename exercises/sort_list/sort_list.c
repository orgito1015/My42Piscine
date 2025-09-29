#include "list.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

t_list* sort_list(t_list* lst, int (*cmp)(int, int))
{
	int flag = 1;
	t_list* cur;

	while (flag)
	{
		flag = 0;
		for (cur = lst; cur && cur->next; cur = cur->next)
		{
			if (!cmp(cur->data, cur->next->data))
			{
				swap(&(cur->data), &(cur->next->data));
				flag = 1;
			}
		}
	}
	return (lst);
}
