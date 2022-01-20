#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (little[j] == 0)
		return ((char *)&big[i]);
	while (big[++i] && i + (size_t)ft_strlen((char *)little) <= len)
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
