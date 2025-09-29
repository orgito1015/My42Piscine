#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"

t_list* sort_list(t_list* lst, int (*cmp)(int, int));

void _print_list(t_list *lst)
{
	t_list* cur;

	for (cur = lst; cur; cur = cur->next)
		printf("%d%s", cur->data, (cur->next ? "," : ""));
	printf("\n");
}

void list_append(t_list** lst, int data)
{
	t_list* n = malloc(sizeof(*n));
	t_list* cur;
	
	n->next = 0;
	n->data = data;

	if (!(*lst))
	{
		*lst = n;
		return;
	}
	for (cur = *lst; cur && cur->next; cur = cur->next)
		;
	cur->next = n;
}
t_list* list_from_int_tab(int *tab, unsigned int size)
{
	t_list* ret = 0;
	unsigned int i;

	for (i = 0; i < size; i++)
		list_append(&ret, tab[i]);

	return ret;
}

int  moulinette_croissant(int a, int b)
{
	return (a <= b);
}

int  moulinette_decroissant(int a, int b)
{
	return (a >= b);
}

void _test(int *tab, unsigned int size, int (*cmp)(int, int))
{
	t_list* orig;
	t_list* n;

	orig = list_from_int_tab(tab, size);
	n = sort_list(orig, cmp);
	_print_list(n);
}

void _realtest(int *tab, unsigned int size)
{
	printf("sort ascending: ");
	_test(tab, size, moulinette_croissant);
	printf("sort descending: ");
	_test(tab, size, moulinette_decroissant);
}

int	main(int argc, char **argv)
{
	unsigned int size;
	
	size = argc - 1;
	int *tab = malloc(size * sizeof(int));
	
	for (unsigned int i = 0; i < size; i++)
		tab[i] = atoi(argv[i + 1]);
	
	_realtest(tab, size);
	
	free(tab);
	
	return (0);
}