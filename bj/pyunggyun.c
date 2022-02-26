#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	double i = *(double *)a;
	double j = *(double *)b;

	if (i < j)
		return (1);
	if (i > j)
		return (-1);
	return (0);

}

double	gophagi(double arr_i, double choidae)
{
	double result = 0;
	result = (arr_i / choidae) * 100;
	return (result);
}

void	gyesan(double *arr, double (*f)(double, double), int n)
{
	int i = 0;
	double choidae = arr[0];
	while (i < n)
	{
		arr[i] = f(arr[i], choidae);
		i++;
	}
}

int main(void)
{
	int n;
	double *arr;

	scanf("%d", &n);
	int i = 0;

	arr = (double *)calloc(sizeof(double), n);
	while (i < n)
	{
		scanf("%lf", &arr[i]);
		i++;
	}
	qsort(arr, n, sizeof(double), compare);
	i = 0;
	gyesan(arr, gophagi, n);
	i = 0;
	double final = 0;
	i = 0;
	while (i < n)
	{
		final += arr[i];
		i++;
	}
	final /= n;
	printf("%lf", final);
}