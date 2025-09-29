#include <unistd.h>


static void ft_putchar(char c)

{

	write(1, &c, 1);

}


void ft_putnbr(int nb)

{

	int	div;


	div = 1;

	while (nb / div >= 10 || nb / div <= -10)

		div *= 10;

	if (nb < 0)

		ft_putchar('-');

	while (div > 0)

	{

		if (nb < 0)

			ft_putchar(nb / div % 10 * -1 + '0');

		else

			ft_putchar(nb / div % 10 + '0');

		div /= 10;

	}

}
