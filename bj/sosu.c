#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, M;
	scanf("%d%d", &N, &M);
	int arr[1000000];
	int i = N;
	int j = 0;
	while (i <= M)
	{
		arr[j] = i;
		i++;
		j++;
	}
	i = 0;
	i = 2;
	j = 0;
	if (N == 1)
		j++;
	while (j < M - N + 1)
	{
		i = 2;
		while (i <= (int)sqrt(M))
		{
			if (arr[j] % i == 0 && arr[j] != i)
			{
				arr[j] = 0;
				break ;
			}
			i++;
		}
		j++;
	}
	j = 0;
	if (N == 1)
		j++;
	while (j < M - N + 1)
	{
		if (arr[j] != 0)
			printf("%d\n", arr[j]);
		j++;
	}
}