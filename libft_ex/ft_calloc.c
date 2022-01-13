#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t	i;

	i = 0;
	str = (unsigned char *)malloc(count * size);
	if (str == 0)
	{
		return (0);
	}
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}