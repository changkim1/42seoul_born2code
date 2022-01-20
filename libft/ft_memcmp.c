#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	       size_t	i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char *)buf1;
	cp2 = (unsigned char *)buf2;
	while (cp1[i] == cp2[i] && i < count)
		i++;
	if (cp1[i] > cp2[i])
		return (1);
	else if (cp1[i] < cp2[i])
		return (-1);
	else
		return (0);
}
