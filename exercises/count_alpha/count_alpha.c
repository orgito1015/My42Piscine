#include <stdio.h>
#include <stdlib.h>
 
char lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return c;
}

int idx(char c)
{
	return (c - 'a');
}
char chr(int i)
{
	return (i + 'a');
}

void count_alpha(char* str)
{
	char c;
	int chars[26];
	int order[27];
	int	i;
	int j;
	int k;
	order[0] = -1;

	for (i = 0; i < 26; ++i)
		chars[i] = 0;

	for (i = j = 0; str[i]; ++i)
	{
		c = lower(str[i]);
		k = idx(c);
		if (c >= 'a' && c <= 'z')
		{
			if (chars[k] == 0)
			{
				order[j++] = k;
				order[j] = -1;
			}
			chars[k]++;		
		}
	}

	for (i = 0; order[i] != -1; ++i)
	{

		printf("%d%c", chars[order[i]], chr(order[i]));
		if (order[i + 1] != -1)
			printf(", ");
	}
}

int main(int ac, char **av)
{
  char *str = av[1];

  if (ac == 2)
  	{
		count_alpha(str);
   	}
  printf("\n");
}
