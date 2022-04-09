#include "ft_printf.h"

int x(int n)
{
	char	*hex;
	char	*str;
	unsigned int tmp;
	int	i;
	int count;

	i = 0;
	tmp = n;
	count = 0;
	hex = (char *)malloc(17);
	make_hex(hex, 'x');
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	str = (char *)malloc(count + 1);
	tmp = n;
	ft_puthex(tmp, str, count, hex);
	return (count);
}

int X(int n)
{
	char	*hex;
	char	*str;
	unsigned int tmp;
	int	i;
	int count;

	i = 0;
	tmp = n;
	count = 0;
	hex = (char *)malloc(17);
	make_hex(hex, 'X');
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	str = (char *)malloc(count + 1);
	tmp = n;
	ft_puthex(tmp, str, count, hex);
	return (count);
}

int i(int n)
{
	
}