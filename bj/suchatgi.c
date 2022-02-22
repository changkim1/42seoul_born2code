#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int	compare(const void *a, const void *b)
{
	int num1, num2;

	num1 = *(int *)a;
	num2 = *(int *)b;

	if (num1 < num2)
		return 1;
	if (num1 > num2)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n, m;
	int *a_n, *a_m, *result, *check;
	scanf("%d", &n);
	a_n = (int *)calloc(sizeof(int), n);
	int i = 0;
	while (i < n)
	{
		scanf("%d", &a_n[i]);
		i++;
	}
	qsort(a_n, n, sizeof(int), compare);
	scanf("%d", &m);
	a_m = (int *)calloc(sizeof(int), m);
	result = (int *)calloc(sizeof(int), m);
	i = 0;
	while (i < m)
	{
		scanf("%d", &a_m[i]);
		i++;
	}
	i = 0;
	int j = 0;
	while (j < m)
	{
		if (a_m[j] > a_n[n / 2])
		{
			i = 0;
			while (i < (n / 2))
			{
				if (a_n[i] == a_m[j])
				{
					result[j] = 1;
					break ;
				}
				i++;
			}
		}
		else
		{
			i = n - 1;
			while (i >= (n / 2))
			{
				if (a_n[i] == a_m[j])
				{
					result[j] = 1;
					break ;
				}
				i--;
			}
		}
		j++;
	}
	i = 0;
	while (i < m)
	{
		printf("%d\n", result[i]);
		i++;
	}
}