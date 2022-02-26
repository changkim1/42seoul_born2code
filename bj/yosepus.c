#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int arr_is_null(int *arr, int n)
{
	int i = 0;
	while (i <= n)
	{
		if (arr[i] != 0)
			return (0);
		i++;
	}
	return (1);
}

void	yosepus(int *arr, int n, int k, int i, int *result, int j)
{
	if (arr_is_null(arr, n))
		return ;
	if (i > n)
		i = i - n;
	if (arr[i] != 0)
	{
		arr[i] = 0;
		result[j] = i;
	}
	int count = 0;
	if (!arr_is_null(arr, n))
	{
		while (count < k)
		{
			if (arr[i] != 0)
				count++;
			if (count != k)
				i++;
			if (i > n)
				i = 1;
		}
	}
	yosepus(arr, n, k, i, result, ++j);
}

int main(void)
{
	int *arr, *result;
	int n, k;
	scanf("%d%d", &n, &k);
	arr = (int *)calloc(sizeof(4), (n + 1));
	result = (int *)calloc(sizeof(4), (n + 1));
	int i = 0;
	while (i <= n)
	{
		arr[i] = i;
		i++;
	}
	i = k;
	int j = 0;
	yosepus(arr, n, k, i, result, j);
	printf("<");
	int idx = 0;
	while (idx < n)
	{
		if (idx != n - 1)
		{
			printf("%d, ", result[idx]);
		}
		else
			printf("%d>", result[idx]);
		idx++;
	}
	return (0);
}