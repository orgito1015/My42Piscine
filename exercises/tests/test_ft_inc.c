#include <stdio.h>
#include <stdlib.h>

void ft_inc(int *a);

int main(int ac, char **av)
{
    int value1;

    if (ac == 2)
    {
        value1 = atoi(av[1]);
        ft_inc(&value1);
        printf("%d", value1);
    }
    return (0);
}