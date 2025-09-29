#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool	uf_is_space(const unsigned char c)
{
	return (c == '\t' || c == ' ' || c == '\r'
	|| c == '\f' || c == '\v' || c == '\n');
}

char	*uf_skip_space(const char *str)
{
	while (uf_is_space(*str) == true)
		str = str + 1;
	return ((char *)str);
}

bool			uf_is_upper(const unsigned char c)
{
	return (c > '@' && c < '[');
}

bool	uf_is_alpha(const unsigned char c)
{
	return ((c > 96 && c < 123) || (c > 64 && c < 91));
}

bool	uf_is_digit(const unsigned char c)
{
	return (c > 47 && c < 58);
}


static char	*uf_atoi_check_base(const char *nbr, bool *neg,
								char *c, size_t base)
{
	*neg = false;
	*c = *nbr;
	nbr = nbr + 1;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			*neg = true;
		*c = *nbr;
		nbr = nbr + 1;
	}
	if (base == 16 && *c == '0' && (*nbr == 'x' || *nbr == 'X'))
	{
		*c = nbr[1];
		nbr = nbr + 2;
	}
	else if (base == 2 && *c == '0' && (*nbr == 'b' || *nbr == 'B'))
	{
		*c = nbr[1];
		nbr = nbr + 2;
	}
	return ((char *)nbr);
}

int			uf_atoi_base(const char *nbr, unsigned int base)
{
	char	c;
	bool	neg;
	int		ret;

	ret = 0;
	nbr = uf_atoi_check_base(uf_skip_space(nbr), &neg, &c, base);
	while (true)
	{
		if (uf_is_digit(c) == true)
			c = c - '0';
		else if (uf_is_alpha(c) == true)
			c = c - (uf_is_upper(c) == true ? 'A' - 10 : 'a' - 10);
		else
			break ;
		if ((unsigned int)c >= base)
			break ;
		ret = ret * base;
		ret = ret + c;
		c = *nbr;
		nbr = nbr + 1;
	}
	if (neg == true)
		ret = -ret;
	return (ret);
}

int			ft_atoi(const char *str)
{
	return (uf_atoi_base(str, 10));
}
