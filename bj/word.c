#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char	*str;
	char	word[1000001];
	int	arr[52] = {};

	scanf("%s", word);
	int len = strlen(word);
	word[len] = 0;
	str = (char *)calloc(sizeof(char), 53);
	int i = 0;
	char c = 'A';
	while (c <= 'Z')
	{
		str[i] = c;
		c++;
		i++;
	}
	c = 'a';
	while (c <= 'z')
	{
		str[i] = c;
		c++;
		i++;
	}
	str[i] = 0;
	i = 0;
	while (i < 52)
	{
		arr[i] = 0;
		i++;
	}
	i = 0;
	int j = 0;
	while (i < len)
	{
		j = 0;
		while (str[j])
		{
			if (word[i] == str[j])
				arr[j]++;
			j++;
		}
		i++;
	}
	i = 0;
	int new_arr[26] = {};
	while (i < 26)
	{
		new_arr[i] = arr[i] + arr[i + 26];
		i++;
	}
	i = 0;
	char *new_str;
	new_str = (char *)calloc(1, 27);
	new_str[27] = 0;
	c = 'A';
	while (c <= 'Z')
	{
		new_str[i] = c;
		c++;
		i++;
	}
	int result = 0;
	i = 0;
	while (i < 26)
	{
		if (new_arr[i] > new_arr[0])
		{
			result = i;
			break ;
		}
		i++;
	}
	i = result;
	while (i < 26)
	{
		if (new_arr[result] < new_arr[i + 1])
			result = i + 1;
		else if (new_arr[result] == new_arr[i + 1])
		{
			printf("?");
			return (0);
		}
		i++;
	}
	printf("%c", new_str[result]);
}