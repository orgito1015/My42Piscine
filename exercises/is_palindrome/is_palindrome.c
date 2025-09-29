#include <unistd.h>

int is_palindrome(char *str)
{
    int i = 0;
    int j = 0;
    
    // Find the length of the string
    while (str[j])
        j++;
    j--; // Last valid index
    
    // Check if the string is a palindrome
    while (i < j)
    {
        if (str[i] != str[j])
            return (0);
        i++;
        j--;
    }
    return (1);
}

int main(int argc, char **argv)
{
    // Check if exactly one argument was provided
    if (argc != 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    
    // Check if the string is a palindrome
    if (is_palindrome(argv[1]))
    {
        // Write the palindrome string
        int i = 0;
        while (argv[1][i])
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    
    // Always write a newline at the end
    write(1, "\n", 1);
    return (0);
} 