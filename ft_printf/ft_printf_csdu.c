#include "ft_printf.h"

int	c(char a)
{
	write(1, &a, 1);
	return (1);
}

int	s(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int d(int n)
{
	int tmp;
	int count;
	char	*str;
	
	count = 0;
	tmp = n;
	if (n < 0)
	{
		count++;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	str = (char *)malloc(count + 1);
	ft_putnbr(n, str, count);
	return (count);
}

int u(int n)
{
	unsigned int tmp;
	int count;
	char	*str;
	
	count = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	str = (char *)malloc(count + 1);
	tmp = n;
	ft_putnbr_u(tmp, str, count);
	return (count);
}
