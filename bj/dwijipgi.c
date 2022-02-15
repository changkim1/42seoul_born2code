#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **dwi(char **str, int a, int b)
{
	int i, j;
	i = 0;
	j = 0;
	while (i <= a)
	{
		j = 0;
		while (j <= b)
		{
			if (str[i][j] == '0')
				str[i][j] = '1';
			else if (str[i][j] == '1')
				str[i][j] = '0';
			j++;
		}
		i++;
	}
	return (str);
}

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	char **str;
	str = (char **)calloc(sizeof(char *), (N + 1));
	int i = 0;
	while (i < N)
	{
		str[i] = (char *)calloc(1, (M + 1));
		scanf("%s", str[i]);
		i++;
	}
	int j;
	i = N - 1;
	int count = 0;
	while (i >= 0)
	{
		j = M - 1;
		while (j >= 0)
		{
			if (str[i][j] == '1')
			{
				str = dwi(str, i, j);
				count++;
			}
			j--;
		}
		i--;
	}
	printf("%d", count);
	return 0;
}