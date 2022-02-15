#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int i, j, N;

	i = 0;
	scanf("%d", &N);
	char **str;
	char *tmp;
	str = (char **)calloc(sizeof(char *), (N + 1));
	tmp = (char *)calloc(sizeof(char ), (51));
	while (i < N)
	{
		str[i] = (char *)calloc(sizeof(char), 51);
		scanf("%s", str[i]);
		i++;
	}
	str[i] = 0;
	i = 0;
	int len = strlen(str[i]);
	strcpy(tmp, str[0]);
	while (i < N)
	{
		j = 0;
		while (j < len)
		{
			if (str[i][j] != tmp[j])
			{
				tmp[j] = '?';
			}
			j++;
		}
		i++;
	}
	printf("%s", tmp);
}