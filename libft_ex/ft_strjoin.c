#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	i = -1;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if(!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))));
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
	{
		str[i] = s2[j];
		i++;
	}
	str[i] = 0;
	return (str);
}