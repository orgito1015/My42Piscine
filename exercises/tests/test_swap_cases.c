#include <unistd.h>
#include <string.h>

char    *swap_cases(char *str);

int main(int ac, char **av)
{
    char    *str = NULL;

    if (ac == 2) {
        str = swap_cases(av[1]);
        write(1, str, strlen(str));
    }
    return (0);
}


