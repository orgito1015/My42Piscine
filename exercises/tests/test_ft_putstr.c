void	{{ft_putstr}}(char *str);

int		main(int ac, char **av)
{
    if (ac == 2)
	    {{ft_putstr}}(av[1]);
	return (0);
}
