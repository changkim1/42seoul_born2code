#include "libft.h"

void	ft_bzero(void *dest, size_t count)
{
	unsigned char *s_dest;
	size_t	i;

	i = 0;
	s_dest = (unsigned char *)dest;
	while (i < count)
	{
		s_dest[i] = 0;
		i++;
	}
}