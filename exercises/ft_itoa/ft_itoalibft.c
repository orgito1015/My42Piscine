#include "libft.h"

static void ft_putnbr_stock(long n, char *str, int *i)
{
  if (n > 9)
{
ft_putnbr_stock(n /10, str, i);
ft_putnbr_stock(n % 10, str, i);
}
else
    str[(*i)++] = n + '0';
}

char *ft_itoa(int n)
{
  char *str;
  int    i;
  long  nbr;

   nbr = n;
if ((str = malloc(sizeof(char) *(ft_nbrlen(nbr))+1 ))) ==NULL)
return (NULL);

i=0
  if(nbr<0)
{
  str[i++] = '-';
  nbr *= -1;
}

ft_putnbr_stock(nbr, str, &i);
str[i] = '\0';
return (str);

}




