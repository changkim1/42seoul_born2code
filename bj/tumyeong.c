#include <stdio.h>
#include <stdlib.h>

void	garigi(int **arr, int start_x, int start_y, int end_x, int end_y)
{
	int i, j;
	i = start_x;
	j = start_y;
	while (i <= end_x)
	{
		j = start_y;
		while (j <= end_y)
		{
			arr[i][j]++;
			j++;
		}
		i++;
	}
}

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int **jwapyo;
	jwapyo = (int **)calloc(sizeof(int *), n);
	int i = 0;
	while (i < n)
	{
		jwapyo[i] = (int *)calloc(sizeof(int), 4);
		scanf("%d%d%d%d", &jwapyo[i][0], &jwapyo[i][1], &jwapyo[i][2], &jwapyo[i][3]);
		i++;
	}
	int **arr;
	arr = (int **)calloc(sizeof(int *), 101);
	i = 0;
	while (i < 101)
	{
		arr[i] = (int *)calloc(sizeof(int), 101);
		i++;
	}
	i = 0;
	int j = 0;
	while (i < 101)
	{
		j = 0;
		while (j < 101)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < n)
	{
		garigi(arr, jwapyo[i][0], jwapyo[i][1], jwapyo[i][2], jwapyo[i][3]);
		i++;
	}
	int count = 0;
	i = 0;
	j = 0;
	while (i < 101)
	{
		j = 0;
		while (j < 101)
		{
			if (arr[i][j] > m)
			{
				count++;
			}
			j++;
		}
		i++;
	}
	printf("%d", count);
}