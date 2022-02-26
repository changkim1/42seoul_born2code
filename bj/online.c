#include <stdio.h>

int main(void)
{
	int P[1000];
	int i, price, count, result;

	i = 0;
	count = 0;
	result = 0;
	int N, M;
	scanf ("%d%d", &N, &M);
	while (i < M)
	{
		scanf("%d", &P[i]);
		i++;
	}
	i = 0;
	int tmp = 0;
	while (count < M - 1)
	{
		i = 0;
		while (i < M - 1)
		{
			if (P[i] < P[i + 1])
			{
				tmp = P[i];
				P[i] = P[i + 1];
				P[i + 1] = tmp;
			}
			i++;
		}
		count++;
	}
	count = 0;
	i = 0;
	result = 0;
	int end_price = 0;
	price = P[M - 1];
	while (price <= P[0])
	{
		count = 0;
		i = 0;
		while (i < M)
		{
			if (price <= P[i])
				count++;
			if (count >= N)
				break ;
			i++;
		}
		if (price * count > result)
		{
			result = price * count;
			end_price = price;
		}
		price++;
	}
	printf("%d %d", end_price, result);
}