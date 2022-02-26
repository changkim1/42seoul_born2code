#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define min(a, b) (a < b ? a : b)

int	min_result(int i, int j, int k)
{
	int result = i;
	if (j < i)
		result = j;
	else if (j > k)
		result = k;
	return (result);
}

int main(void)
{
	int	N, i, j;
	scanf("%d", &N);
	int	arr[N + 1][3];

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < 3)
		{
			scanf("%d", &arr[i][j]); 
			j++;
		}
		i++;
	}
	i = 1;
	while (i < N)
	{
		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]);
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]);
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]);
		i++;
	}
	int result = min(min(arr[N-1][0], arr[N-1][1]), arr[N-1][2]);
	printf("%d", result);
}