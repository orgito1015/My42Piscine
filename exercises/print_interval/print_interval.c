#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    if (argc != 2 || !argv[1])
    {
        write(1, "\n", 1);
        return (0);
    }

    i = 0;
    while (argv[1][i])
    {
        if ((i + 1) % 15 == 0)  // Multiple of both 3 and 5
            write(1, "5", 1);
        else if ((i + 1) % 5 == 0)  // Multiple of 5
            write(1, "3", 1);
        else if ((i + 1) % 3 == 0)  // Multiple of 3
            write(1, "5", 1);
        else
            write(1, &argv[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}
