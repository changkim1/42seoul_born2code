#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	r;
	size_t	i;
	char	*str;

	l = 0;
	r = ft_strlen (s1);
	i = -1;
	while (ft_find_set(set, s1[l]))
		l++;
	while (ft_find_set(set, s1[r]))
		r--;
	if (!(str = (char *)malloc(sizeof(char) * (r - l + 1))));
		return (0);
	while (l <= r)
	{
		str[++i] = s1[l];
		l++;
	}
	str[i] = 0;
	return (str);
}

int	ft_find_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}