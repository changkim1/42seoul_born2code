#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (little[j] == 0)
		return ((char *)&big[i]);
	while (big[++i] && i + (size_t)ft_strlen(little) <= len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			j++;
			if (little[j] == 0)
				return ((char *)&big[i]);
		}
	}
	return (0);
}