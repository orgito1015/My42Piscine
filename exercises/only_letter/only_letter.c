#include <unistd.h>

int main()
{
	write(1, "{{letter}}", 1);
	return (0);
}
