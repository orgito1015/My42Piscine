
int     occ_{{letter}}(char *str)
{
    int count;
    
    count = 0;
    while (*str)
    {
        if (*str == '{{letter|upper}}')
            count++;
        str++;
    }
    return (count);
} 