#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int is_this_hansu(int n)
{
	int i = 0;
	int count = 0;
	int n_c = n;
	while (n_c > 0)
	{
		n_c /= 10;
		count++;
	}
	int *tmp = (int *)calloc(sizeof(char), count);
	while (i < count)
	{
		tmp[i] = n % 10;
		n /= 10;
		i++;
	}
	i = count - 1;
	int cha = (tmp[0] - tmp[1]) * (-1);

	while (i > 0)
	{
		if (tmp[i] - tmp[i - 1] != cha)
		{
			free(tmp);
			return (0);
		}	
		i--;
	}
	free(tmp);
	return (1);
} 

int main(void)
{
	int n;
	scanf("%d", &n);
	int *arr;
	int result = 0;
	int i = 1;
	while (i <= n)
	{
		if (is_this_hansu(i) == 1)
			result++;
		i++;
	}
	printf("%d", result);
}