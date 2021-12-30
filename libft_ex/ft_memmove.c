#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	unsigned char	*s_dest;
	unsigned char	*c_src;
	size_t	i;

	s_dest = (unsigned char *)dest;
	c_src = (unsigned char *)src;
	i = -1;
	if (dest == 0)
		return (0);
	if (s_dest > c_src)
	{
		i = n + 1;
		while (--i > 0)
			s_dest[i] = c_src[i];
	}
	else
	{
		while (++i < n)
			s_dest[i] = c_src[i];
	}
	return (dest);
}