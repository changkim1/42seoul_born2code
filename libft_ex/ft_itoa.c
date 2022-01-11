#include <stdio.h>
#include "libft.h"

int	how_many_ten(int n) // n != 0
{
	int	num;

	num = 0;
	if (n < 0)
	{
		n *= -1;
		num++;
	}
	while (n > 0)
	{
		n /= 10;
		num++;
	}
	return (num - 1);
}

char	*ft_itoa(int n)
{
	int	i;
	int	cp_n;
	char	*str;

	i = 0;
	if (n == 0)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (how_many_ten(n) + 1))))
		return (0);
	i = how_many_ten(n);
	cp_n = n;
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
	str[how_many_ten(cp_n) + 1] = 0;
	return (str);
}