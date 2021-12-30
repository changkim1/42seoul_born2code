#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t 	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	while (i < n - 1 && i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > 0)
		dest[i] = 0;
	return (src_len);
}