#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)

void	ft_solve(int **arr, int n, int i, int **result)
{
	i++;
	if (i == n)
		return ;
	result[i] = (int *)calloc(sizeof(int), (i + 1));
	int j = 0;
	while (j < (i + 1))
	{
		if (j == 0)
		{
			result[i][j] = arr[i][0] + result[i - 1][0];
		}
		else if (j == i)
		{
			result[i][j] = result[i - 1][j - 1] + arr[i][j];
		}
		else
		{
			result[i][j] = max(arr[i][j] + result[i - 1][j - 1], (arr[i][j]) + result[i - 1][j]);
		}
		j++;
	}
	ft_solve(arr, n, i, result);
}

int main(void)
{
	int n, i, **arr;
	scanf("%d", &n);
	i = 0;
	arr = (int **)calloc(sizeof(int *), n);
	int j = 0;
	while (i < n)
	{
		arr[i] = (int *)calloc(sizeof(int), (i + 1));
		j = 0;
		while (j < (i + 1))
		{
			scanf("%d", &arr[i][j]);
			j++;
		}
		i++;
	}
	int **result;
	result = (int **)calloc(sizeof(int *), n);
	result[0] = (int *)calloc(sizeof(int), 1);
	result[0][0] = arr[0][0];
	i = 0;
	ft_solve(arr, n, i, result);
	i = n - 1;
	j = 0;
	int final = result[i][0];
	while (j < i)
	{
		final = max(final, result[i][j + 1]);
		j++;
	}
	printf("%d", final);
}