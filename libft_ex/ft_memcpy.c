#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*s_dest;
	const char	*c_src;
	size_t	i;

	s_dest = (unsigned char *)dest;
	c_src = (const char *)src;
	i = 0;
	if (dest == 0)
		return (0);
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		s_dest[i] = c_src[i];
		i++;
	}
	return (dest);
}