#include <stdio.h>
#include <stdlib.h>

void ft_mul(int *a, int value);

int main(int ac, char **av)
{
    int value1;
    int value2;

    if (ac == 3)
    {
        value1 = atoi(av[1]);
        value2 = atoi(av[2]);
        ft_mul(&value1, value2);
        printf("%d", value1);
    }
    return (0);
}