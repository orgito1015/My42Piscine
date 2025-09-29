char	*ft_strrev(char *str)
{
	int	len;
	int	i;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	while (i < len / 2)
	{
		str[i] = str[i] ^ str[len - 1 - i];
		str[len - 1 - i] = str[i] ^ str[len - 1 - i];
		str[i] = str[i] ^ str[len - 1 - i];
		i = i + 1;
	}
	return (str);
}
