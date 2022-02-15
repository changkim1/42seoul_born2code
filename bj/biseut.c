#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	char **word;
	word = (char **)calloc(sizeof(char *), (N + 1));
	int i = 0;
	while (i < N)
	{
		word[i] = (char *)calloc(1, 51);
		scanf("%s", word[i]);
		i++;
	}
	i = 0;
	int len = strlen(word[0]);
	i = 0;
	int j = 0;
	int k = 0;
	char count = '1';
	char *tmp;
	int idx;
	tmp = (char *)calloc(1, len);
	while (i < N)
	{
		idx = 0;
		while (idx < len)
		{
			tmp[idx] = 'a';
			idx++;
		}
		j = 0;
		while (j < len)
		{
			k = j;
			while (k < len)
			{
				if (word[i][j] == word[i][k] && tmp[k] > count)
					tmp[k] = count;
				k++;
			}
			count++;
			j++;
		}
		strcpy(word[i], tmp);
		count = '1';
		i++;
	}
	i = 0;
	int result = 0;
	while (i < N - 1)
	{
		j = 1;
		while (i + j < N)
		{
			if (!strcmp(word[i], word[i + j]))
				result++;
			j++;
		}
		i++;
	}
	printf("%d\n", result);
}