#include <stdio.h>

char *ft_array(char *str)
{
	int i;

	i = 0;
	while (str[i]) // a[i] -> a라는 문자열 내에서 i번째
	{
		str[i] = str[i] + 1;
		i++;
	}
	return (str);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_array_minus(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i] - 1;
		i++;
	}
	return (str);
}

int main(void)
{
	char str[5];
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = 0;
	ft_array(str);
	printf("%s\n", str);
	
	ft_array_minus(str);
	printf("%s\n", str);

	printf("%d\n", ft_strlen(str));
	return 0;
}