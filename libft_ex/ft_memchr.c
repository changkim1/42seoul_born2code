#include <string.h>

void	*memchr(const void *buf, int c, size_t count)
{
	size_t	i;
	unsigned char	*cp_buf;

	i = 0;
	cp_buf = (unsigned char *)buf;
	while (cp_buf[i] && i < count)
	{
		if (cp_buf[i] == (unsigned char)c)
		{
			return ((void *)&cp_buf[i]);
		}
		i++;
	}
	return (0);
}