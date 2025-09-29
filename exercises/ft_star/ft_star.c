#include <unistd.h>

void	ft_star(void)
{
	write(1, "*******\n", 8);
}


int main(void)
{
	ft_star();
}