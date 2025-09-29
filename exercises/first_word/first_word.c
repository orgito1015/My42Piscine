#include <stdio.h>
#include <unistd.h>

void print_upto(char* start, char* end)
{
	while (start != end)
	{
		write(1, start, 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	char* start;
	char* end;

	if (argc == 2)
	{
		start = argv[1];
		while (*start == ' ' || *start == '\t')
			start++;		
		end = start;
		while (*end && *end != ' ' && *end != '\t')
			end++;
		print_upto(start, end);
	}
	write(1, "\n", 1);

	return (0);
}
