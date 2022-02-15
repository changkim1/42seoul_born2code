#include <stdio.h>

int main(void)
{
	int	i = 0;
	int	N;

	scanf("%d", &N);
	int arr[N];
	while (i < N)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	int count = 0;
	int tmp;
	while (count < N - 1)
	{
		i = 0;
		while (i < N - 1)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}
			i++;
		}
		count++;
	}
	i = 0;
	int result = 0;
	if (N % 2 == 1)
		result = (arr[(N / 2)] * arr[(N / 2)]);
	else if (N % 2 == 0)
		result = (arr[0] * arr[(N - 1)]);
	printf("%d", result);
}