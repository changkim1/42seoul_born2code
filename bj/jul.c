#include <stdio.h>

int main(void)
{
	int N;
	scanf("%d", &N);
	int arr[N];
	int result[N];
	int i = 0;
	while (i < N)
	{
		scanf("%d", &arr[i]);
		i++;
	}
	i = 0;
	int idx = 0;
	int count = 0;
	i = 0;
	while (i < N)
	{
		result[i] = 0;
		i++;
	}
	i = 0;
	while (i < N - 1)
	{
		if (arr[i] == 0)
		{
			count++;
			idx = i;
		}
		i++;
	}
	if (count == 0)
		result[0] = i + 1;
	result[arr[0]] = 1;
	int j = 0;
	i = 1;
	int k = 0;
	count = 0;
	while (i < N)
	{
		j = 0;
		k = arr[i];
		while (result[k] != 0)
			k++;
		while (k < N)
		{
			if (result[k] != 0)
			{
				k++;
				continue ;
			}
			count = 0;
			j = 0;
			while (j < k)
			{
				if (result[j] < i + 1 && result[j] != 0)
					count++;
				j++;
			}
			if (count == k - arr[i])
				break ;
			k++;
		}
		result[k] = i + 1;
		i++;
	}
	i = 0;
	while (i < N)
	{
		printf("%d ", result[i]);
		i++;
	}
}