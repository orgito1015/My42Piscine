#include <stdio.h>

int     occ_{{letter}}(char *str);

int main(int ac, char **av)
{
    int i = 0;

    while (ac > 1) {
        i = occ_{{letter}}(av[1]);
        printf("%d\n", i);
        av++;
        ac--;
    }
    return (0);
}