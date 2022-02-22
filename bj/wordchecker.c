#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	is_it_word(char *str, int n)
{
	int i = 0;
	int k = 0;
	int j = 0;
	int	len = strlen(str);

	while (i < len)
	{
		j = 0;
		while (str[i + j] && str[i] == str[i + j])
		{
			j++;
		}
		while (str[i + j] && str[i] != str[i + j])
			j++;
		while (str[i + j])
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int main(void)
{
	int n, i, count;
	char **str;
	scanf("%d", &n);
	str = (char **)calloc(sizeof(char*), (n + 1));
	i = 0;
	count = 0;
	while (i < n)
	{
		str[i] = (char *)calloc(1, 101);
		scanf("%s", str[i]);
		count += is_it_word(str[i], n);
		i++;
	}
	printf("%d", count);
	return (0);
}