#include <unistd.h>

void	odd(void)
{
	write(1, "13579\n", 6);
}

int main(void)
{
	odd();
}