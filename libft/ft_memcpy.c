#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	      char	*c_dest;
	const char	*c_src;
	    size_t	i;

	c_dest = dest;
	c_src = src;
	i = 0;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		c_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}
