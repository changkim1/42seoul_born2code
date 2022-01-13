#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char	*c_dest;
	char	*c_src;
	size_t	i;

	c_dest = dest;
	c_src = (char *)src; 
	i = -1;
	if (dest == 0)
		return (0);
	if (c_dest > c_src)
	{
		i = num + 1;
		while ((int)--i >= 0)
			c_dest[i] = c_src[i];
	}
	else
	{
		while (++i < num)
			c_dest[i] = c_src[i];
	}
	return (dest);
}