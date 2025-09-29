#include <stdlib.h>

int		ndigits(int n, int base)
{
	if (n > -base && n < base)
		return (1);
	return (1 + ndigits(n / base, base));
}

void	render_number(int n, int base, char *result)
{
	static const char *digits = "0123456789ABCDEF";

	if (n <= - base || n >= base)
		render_number(n / base, base, result - 1);
	if (n >= 0)
		*result = digits[n % base];
	else
		*result = digits[-(n % base)];
}

char	*ft_itoa_base(int value, int base)
{
	int		minus;
	int		n;
	char	*result;

	minus = (base == 10 && value < 0);
	n = ndigits(value, base);
	result = (char*)malloc(sizeof(char) * (minus + n + 1));
	if (result == NULL)
		return (NULL);
	if (minus)
		result[0] = '-';
	render_number(value, base, result + minus + n - 1);
	result[minus + n] = '\0';
	return (result);
}


char	*ft_itoa(int nbr)
{
	return (ft_itoa_base(nbr, 10));
}