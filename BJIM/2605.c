#include <stdio.h>
#define MAX 101

int	array[MAX];
int	num[MAX];
int n;

void	swap(int idx)
{
	int tmp;

	tmp = array[idx];
	array[idx] = array[idx - 1];
	array[idx - 1] = tmp;
}

int main(void)
{
	int idx;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
		array[i] = i + 1;
	}
	for (int i = 0; i < n; i++)
	{
		idx = i;
		for (int j = 0; j < num[i]; j++)
		{
			swap(idx);
			idx--;
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
}