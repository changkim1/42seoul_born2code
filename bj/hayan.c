#include <stdio.h>
#include <stdlib.h>
#define W 'W'
#define B 'B'

char	it_is_W(int hap)
{
	if (hap % 2 == 0)
		return (W);
	else
		return (B);
}

int main(void)
{
	int	i, j;

	char **str1;
	char **str2;
	str1 = (char **)calloc(sizeof(char *), 9);
	str2 = (char **)calloc(sizeof(char *), 9);
	i = 0;
	while (i < 8)
	{
		str2[i] = (char *)calloc(sizeof(char), 9);
		scanf("%s", str2[i]);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (i == 0 && j == 0)
			str1[0][0] = W;
		str1[i] = (char *)calloc(sizeof(char), 9);		
		j = 0;
		while (j < 8)
		{
			str1[i][j] = it_is_W(i + j);
			j++;
		}
		i++;
	}
	int	count = 0;
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (str1[i][j] == W && str2[i][j] == 'F')
				count++;
			j++;
		}
		i++;
	}
	printf("%d", count);
	return (0);
}