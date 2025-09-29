#include <unistd.h>

void ft_putc(int c) { write( 1, &c, 1);}

void ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb/10);
	ft_putc((nb % 10) + '0');
}

int main(void)
{
	int i = 0;

	while(++i <= 100)
	{
		if ( i % 5 == 0 && i % 3 == 0) write( 1, "{{fizz}}{{buzz}}", 8);
		else if ( i % 3 == 0 ) write( 1, "{{fizz}}", 4);
		else if ( i % 5 == 0 ) write( 1, "{{buzz}}", 4);
		else ft_putnbr(i);
		ft_putc('\n');	
	}
	return 0;
}
