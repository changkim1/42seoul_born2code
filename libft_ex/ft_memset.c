#include <string.h>

void	*ft_memset(void *dest, int value, size_t count)
{
	size_t	i;
	unsigned char	*s_dest;
	
	i = 0;
	s_dest = (unsigned char *)dest;
	while (i < count)
	{
		s_dest[i] = (unsigned char)value;
		i++;
	}
	return (dest);
}