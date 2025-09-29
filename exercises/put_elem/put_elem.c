#include "ft_list.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void ft_list_foreach(t_list *begin_list, void (*f)(void *));
void ft_print_str_list(t_list *list);
t_list *ft_list_push_back(t_list *begin_list, void *data);

void put_elem(void *data) {
  char *str = data;

  write(1, str, strlen(str));
  write(1, "\n", 1);
}

int     main(int ac, char **av)
{
  t_list	*list = NULL;
  int		i;

  --ac;
  ++av;
  for (i = 0; i < ac; i++)
  {
    list = ft_list_push_back(list, av[i]);
  }
  ft_list_foreach(list, (void (*)(void *))&put_elem);
  return (0);
}
