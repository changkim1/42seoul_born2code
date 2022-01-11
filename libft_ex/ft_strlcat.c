#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen((char *)src);
	if (len <= d_len)
		return (len + s_len);
	else
	{
		while (src[i] != 0 && d_len + i < len - 1)
		{
			dest[d_len + i] = src[i];
			i++;
		}
		return (d_len + s_len);
	}
}