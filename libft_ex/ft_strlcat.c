#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (n <= ft_strlen(dest))
		return (ft_strlen(dest) + ft_strlen(src));
	while (dest[i])
		i++;
	else
	{
		while ()
	}
}