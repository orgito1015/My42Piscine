#include <stdlib.h>
#include <string.h>

char	is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\0');
}

int		calc_nbr_words(char *str)
{
	int	i = 0;
	int	word = 0;
	
	for (; str[i] != '\0'; i++)
	{
		if (!is_separator(str[i]) && is_separator(str[i + 1]))
			word++;
	}
	return word;
}

char	*ft_strncpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while(s2[i] && i < n)
	{
		s1[i] = s2[i];
		i = i + 1;
	}
	s1[i] = '\0';
	return (s1);
}

void	copy_words(char **tab, char *str)
{
	int	i = 0;
	int	word = 0;
	int	start = 0;
	int	length = 0;
	
	for (; str[i] != '\0'; i++)
	{
		if (!is_separator(str[i]) && is_separator(str[i + 1]))
		{
			length = i - start + 1;
			tab[word] = malloc(sizeof(**tab) * (length + 1));
			ft_strncpy(tab[word], str + start, length);
			tab[word][length] = '\0';
			word++;
		}
		if (is_separator(str[i]) && !is_separator(str[i + 1]))
			start = i + 1;
	}
	tab[word] = NULL;
}

char	**ft_split(char *str)
{
	char	**tab;
	int		nbr_words;
	
	nbr_words = calc_nbr_words(str);
	tab = malloc(sizeof(*tab) * (nbr_words + 1));
	copy_words(tab, str);
	return (tab);
}

