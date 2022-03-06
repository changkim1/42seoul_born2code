#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	word_check(char *str)
{
	int i;
	int j;
	char	*checker;
	
	checker = (char *)malloc(sizeof(char) * 27);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (strchr(checker, str[i]))
			return (0);
		checker[j] = str[i];
		while (str[i] == checker[j])
			i++;
		j++;
	}
	return (1);
}

int main(void)
{
	int count = 0;
	int n;

	scanf("%d", &n);
	char **str = (char **)calloc(sizeof(char *), (n + 1));
	int i = 0;
	while (i < n)
	{
		str[i] = (char *)calloc(sizeof(char), 101);
		scanf("%s", str[i]);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (word_check(str[i]))
			count++;
		i++;
	}
	printf("%d", count);
	return (0);
}