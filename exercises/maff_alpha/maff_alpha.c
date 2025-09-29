#include <unistd.h>

int main()
{
	char c;
	char d;

	for (c = 'a'; c <= 'z'; c++)
	{
		if ((c - 'a') % 2)
			d = c - ('a' - 'A');
		else
			d = c;
		write(1, &d, 1);
	}
	write(1, "\n", 1);
	return (0);
}
