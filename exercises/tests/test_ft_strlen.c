#include <stdio.h>

int     {{ft_strlen}}(char *str);

int main(int ac, char **av)
{
    int i = 0;

    while (ac > 1) {
        i = {{ft_strlen}}(av[1]);
        printf("%d\n", i);
        av++;
        ac--;
    }
    return (0);
}