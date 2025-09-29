#include "ft_list.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_list_foreach(t_list *begin_list, void (*f)(void *));
void ft_print_int_list(t_list *list);
t_list *ft_list_push_back(t_list *begin_list, void *data);

void inc_elem(void *data) {
  int *ptr = data;
  (*ptr)++;
}

int     main(int ac, char **av)
{
  t_list	*list = NULL;
  int		i;

  --ac;
  ++av;
  for (i = 0; i < ac; i++)
  {
    int *data = malloc(sizeof(int));
    *data = atoi(av[i]);
    list = ft_list_push_back(list, data);
  }
  ft_list_foreach(list, &inc_elem);
  ft_print_int_list(list);
  return (0);
}
