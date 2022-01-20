#include "libft.h"

int	how_many_tens(int n)
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
	str = (char *)malloc(sizeof(char) * (how_many_tens(n) + 1));
	if (!str)
		return (0);
	i = how_many_tens(n);
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
	str[how_many_tens(cp_n) + 1] = 0;
	return (str);
}
