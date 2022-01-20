//#include "libft.h"
#include <unistd.h>

int	how_many_ten(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	zero_and_minus(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
	}
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	 int	i;
	 int	c_n;
	char	str[20];

	c_n = n;
	if (n == 0 || n == -2147483648)
	{
		zero_and_minus(n, fd);
		return ;
	}
	if (c_n < 0)
	{
		str[0] = '-';
		c_n *= -1;
	}
	i = how_many_ten(n);
	while (c_n > 0)
	{
		str[--i] = c_n % 10 + '0';
		c_n /= 10;
	}
	str[how_many_ten(n)] = 0;
	i = -1;
	while (str[++i])
		write(fd, &str[i], 1);
}
