#include <unistd.h>
#include <stdlib.h>
#include "g_diam.h"

void	ft_put_positive_nbr(int n)
{
	long	p;
	int		digit;
	char	c;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	p = 1;
	while (p <= n)
		p *= 10;
	p /= 10;
	while (p > 0)
	{
		digit = n / p;
		n -= digit * p;
		p /= 10;
		c = '0' + digit;
		write(1, &c, 1);
	}
}

void	ft_putstr(char *s)
{
	int len;

	len = 0;
	while (s[len] != 0)
		len++;
	write(1, s, len);
}

char	*ft_strndup(char *str, int n)
{
	char	*res;
	int		i;

	res = (char*)malloc(sizeof(char) * (n + 1));
	if (res)
	{
		i = 0;
		while (i < n)
		{
			res[i] = str[i];
			i++;
		}
		res[i] = 0;
	}
	return (res);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*res;

	len = 0;
	while (str[len] != 0)
		len++;
	res = ft_strndup(str, len);
	return (res);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		if (s1[i] != s2[i])
			return (s2[i] - s1[i]);
		i++;
	}
	return (s2[i] - s1[i]);
}

t_node	*get_node(t_node_list **all_nodes, char *number)
{
	t_node_list	*element;
	t_node_list	*prev;
	t_node		*new_node;
	t_node_list	*new_element;

	element = *all_nodes;
	prev = NULL;
	while (element != NULL)
	{
		if (ft_strcmp(number, element->node->number) == 0)
		{
			return (element->node);
		}
		prev = element;
		element = element->next;
	}
	// node doesn't exist yet
	new_node = (t_node*)malloc(sizeof(t_node));
	new_element = (t_node_list*)malloc(sizeof(t_node_list));
	if (new_node && new_element)
	{
		new_node->connected_to = NULL;
		new_node->number = ft_strdup(number);
		new_element->node = new_node;
		new_element->next = NULL;
		if (prev)
			prev->next = new_element;
		else
			*all_nodes = new_element;
	}
	return (new_node);
}

void	connect_node_to(t_node *node, t_node *target)
{
	t_node_list *new_connection;
	t_node_list *element;
	t_node_list *prev;

	element = node->connected_to;
	prev = NULL;
	while (element != NULL)
	{
		if (ft_strcmp(element->node->number, target->number) == 0)
		{
			return ;
		}
		prev = element;
		element = element->next;
	}
	new_connection = (t_node_list*)malloc(sizeof(t_node_list));
	if (new_connection)
	{
		new_connection->next = NULL;
		new_connection->node = target;
		if (prev == NULL)
			node->connected_to = new_connection;
		else
			prev->next = new_connection;
	}
}

void	add_connection(t_node_list **all_nodes, char *first_node_number,
		char *second_node_number)
{
	t_node	*first_node;
	t_node	*second_node;

	first_node = get_node(all_nodes, first_node_number);
	second_node = get_node(all_nodes, second_node_number);
	connect_node_to(first_node, second_node);
	connect_node_to(second_node, first_node);
}

void	print_nodes(t_node_list *all_nodes)
{
	t_node_list	*connected_to;
	t_node		*node;

	while (all_nodes != NULL)
	{
		node = all_nodes->node;
		ft_putstr("Node ");
		ft_putstr(node->number);
		ft_putstr("\n");
		connected_to = node->connected_to;
		if (connected_to != NULL)
		{
			ft_putstr("   connected to ");
			while (connected_to != NULL)
			{
				ft_putstr(connected_to->node->number);
				ft_putstr(" ");
				connected_to = connected_to->next;
			}
			ft_putstr("\n");
		}
		all_nodes = all_nodes->next;
	}
}

int		is_node_in(char *number, t_node_list *list)
{
	while (list != NULL)
	{
		if (ft_strcmp(list->node->number, number) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

void	prepend_node(t_node_list **list, t_node *node)
{
	t_node_list *new_element;

	new_element = (t_node_list*)malloc(sizeof(t_node_list));
	if (new_element)
	{
		new_element->node = node;
		if (*list == NULL)
			new_element->next = NULL;
		else
			new_element->next = *list;
		*list = new_element;
	}
}

void	remove_first_node(t_node_list **list)
{
	t_node_list *first;

	if (*list != NULL)
	{
		first = *list;
		*list = (*list)->next;
		free(first);
	}
}

int		longest_path_from(t_node *node, t_node_list *visited_nodes)
{
	t_node_list	*connected_node;
	int			longest;
	int			longest_next;

	if (node->connected_to == NULL)
		return (1);
	prepend_node(&visited_nodes, node);
	longest = 1;
	connected_node = node->connected_to;
	while (connected_node != NULL)
	{
		if (is_node_in(connected_node->node->number, visited_nodes))
			longest_next = 1;
		else
		{
			longest_next = longest_path_from(connected_node->node, visited_nodes) + 1;
		}
		if (longest_next > longest)
			longest = longest_next;
		connected_node = connected_node->next;
	}
	remove_first_node(&visited_nodes);
	return (longest);
}

int		look_for_longest_path(t_node_list *all_nodes)
{
	int		longest_path;
	int		longest_path_from_this_node;
	t_node	*starting_point;

	longest_path = 0;
	while (all_nodes != NULL)
	{
		starting_point = all_nodes->node;
		longest_path_from_this_node = longest_path_from(starting_point, NULL);
		if (longest_path_from_this_node > longest_path)
			longest_path = longest_path_from_this_node;
		all_nodes = all_nodes->next;
	}
	return (longest_path);
}

void	g_diam(char *str)
{
	t_node_list	*all_nodes;
	int			i;
	int			pos;
	char		*first_node;
	char		*second_node;
	int			longest_path;

	all_nodes = NULL;
	i = 0;
	pos = -1;
	while (str[i] != 0)
	{
		if (str[i] == '-')
		{
			first_node = ft_strndup(&(str[pos + 1]), i - pos - 1);
			pos = i;
		}
		else if (str[i] == ' ')
		{
			second_node = ft_strndup(&(str[pos + 1]), i - pos - 1);
			pos = i;
			add_connection(&all_nodes, first_node, second_node);
			free(first_node);
			free(second_node);
		}
		i++;
	}
	second_node = ft_strndup(&(str[pos + 1]), i - pos - 1);
	pos = i;
	add_connection(&all_nodes, first_node, second_node);
	free(first_node);
	free(second_node);
	//print_nodes(all_nodes);
	longest_path = look_for_longest_path(all_nodes);
	ft_put_positive_nbr(longest_path);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		g_diam(argv[1]);
	ft_putstr("\n");
	return (0);
}
