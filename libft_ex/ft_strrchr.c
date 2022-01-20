char	*ft_strrchr(const char *str, int c)
{
    int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == (char)c)
	{
		return ((char *)&str[i]);
	}
	while (i < 0)
	{
		i--;
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
	}
	return (0);
}
