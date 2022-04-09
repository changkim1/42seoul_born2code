#include "ft_printf.h"

void	ft_putnbr(int n, char *str, int count)
{
	int i;

	i = count;
	str[i] = 0;
	i--;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	write(1, str, count);
	free(str);
}

void	ft_putnbr_u(unsigned int n, char *str, int count)
{
	int i;

	i = count;
	str[i] = 0;
	i--;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	write(1, str, count);
	free(str);
}

void	make_hex(char *str, char checker)
{
	int i;
	char c;

	i = 0;
	if (checker == 'x')
		c = 'a';
	else if (checker == 'X')
		c = 'A';
	while (i < 10)
	{
		str[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		str[i] = c;
		i++;
		c++;
	}
	str[i] = 0;
}

void	ft_puthex(unsigned int n, char *str, int count, char *hex)
{
	int i;

	i = count;
	str[i] = 0;
	i--;
	while (n > 0)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	write(1, str, count);
	free(str);
	free(hex);
}

int	check_base(char *str)
{
	
}