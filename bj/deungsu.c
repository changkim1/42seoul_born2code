#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;
	if (num2 < num1)
		return 1;
	return 0;
}

int main(void)
{
	int *yesang;
	int *silje;
	int *bulman;
	int N;
	int i;
	long long result;

	scanf("%d", &N);
	i = 0;
	yesang = (int *)malloc(sizeof(int) * N);
	silje = (int *)malloc(sizeof(int) * N);
	bulman = (int *)malloc(sizeof(int) * N);
	while (i < N)
	{
		scanf("%d", &yesang[i]);
		i++;
	}
	i = 0;
	int count = 0;
	qsort(yesang, N, sizeof(int), compare);
	i = 0;
	while (i < N)
	{
		silje[i] = i + 1;
		i++;
	}
	i = 0;
	result = 0;
	while (i < N)
	{
		bulman[i] = yesang[i] - silje[i];
		i++;
	}
	i = 0;
	while (i < N)
	{
		if (bulman[i] < 0)
			bulman[i] *= (-1);
		result = result + bulman[i];
		i++;
	}
	printf("%lld", result);
}