#include <stdlib.h>
#include <unistd.h>

// Function to get string length
int ft_strlen(char *str) {
    int len = 0;
    while (str[len])
        len++;
    return len;
}

// Function to check if a number is zero
int is_zero(char *str) {
    while (*str == '-' || *str == '+')
        str++;
    
    while (*str && *str == '0')
        str++;
    
    return (*str == '\0');
}

// Function to write a string to stdout
void ft_putstr(char *str) {
    int len = 0;
    while (str[len])
        len++;
    write(1, str, len);
}

// Function to handle the multiplication of two positive number strings
char *multiply(char *s1, char *s2) {
    int len1 = ft_strlen(s1);
    int len2 = ft_strlen(s2);
    int len = len1 + len2;
    
    // Allocate result array and initialize to 0
    int *res = malloc(len * sizeof(int));
    if (!res)
        return NULL;
    
    // Initialize array to zero (replacing calloc)
    for (int i = 0; i < len; i++)
        res[i] = 0;
    
    // Reverse indices for easier calculation
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int pos1 = i + j;
            int pos2 = i + j + 1;
            int mul = (s1[i] - '0') * (s2[j] - '0');
            
            int sum = mul + res[pos2];
            
            res[pos1] += sum / 10;
            res[pos2] = sum % 10;
        }
    }
    
    // Convert to string
    char *result = malloc(len + 1);
    if (!result) {
        free(res);
        return NULL;
    }
    
    int i = 0, j = 0;
    // Skip leading zeros
    while (i < len - 1 && res[i] == 0)
        i++;
    
    // Convert digits to characters
    while (i < len)
        result[j++] = res[i++] + '0';
    
    result[j] = '\0';
    free(res);
    
    return result;
}

int main(int argc, char **argv) {
    if (argc != 3)
        return 0;
    
    char *num1 = argv[1];
    char *num2 = argv[2];
    
    // Check for zero
    if (is_zero(num1) || is_zero(num2)) {
        write(1, "0\n", 2);
        return 0;
    }
    
    // Determine the sign of the result
    int sign = 1;
    if (num1[0] == '-') {
        sign *= -1;
        num1++;
    }
    if (num2[0] == '-') {
        sign *= -1;
        num2++;
    }
    
    // Multiply the positive numbers
    char *result = multiply(num1, num2);
    if (!result)
        return 1;
    
    // Print the result with appropriate sign
    if (sign == -1)
        write(1, "-", 1);
    ft_putstr(result);
    write(1, "\n", 1);
    
    free(result);
    return 0;
}
    