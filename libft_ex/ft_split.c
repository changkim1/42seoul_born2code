#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char	**str;

	i = 0;
	if (str = (char **)malloc(sizeof(char *) * (index_num(s, c) + 1)))
		return (0);
	index = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] != c)
				j++;
			str[index] = ft_substr(s, i, j - i);
			index++;
			i = j;
		}
		i++;
	}
	str[index] = 0;
	return (str);
}

int	index_num(char const *s, char c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			num++;	
	}
	return (num);
}