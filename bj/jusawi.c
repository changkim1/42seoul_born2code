#include <stdio.h>

int main(void)
{
	int one, two, thr, idx;
	int	i[20];
	int	j[20];
	int	k[40];

	scanf("%d%d%d", &one, &two, &thr);
	idx = 0;
	while (idx <= one)
	{
		i[idx] = idx;
		idx++;
	}
	idx = 0;
	while (idx <= two)
	{
		j[idx] = idx;
		idx++;
	}
	idx = 0;
	while (idx <= thr)
	{
		k[idx] = idx;
		idx++;
	}
	idx = 0;
	int	hap[80];
	while (idx <= one + two + thr)
	{
		hap[idx] = 0;
		idx++;
	}
	int idx_i, idx_j, idx_k;
	idx_i = 1;
	while (idx_i <= one)
	{
		idx_j = 1;
		while (idx_j <= two)
		{
			idx_k = 1;
			while (idx_k <= thr)
			{
				hap[idx_i + idx_j + idx_k]++;
				idx_k++;
			}
			idx_j++;
		}
		idx_i++;
	}
	idx = 0;
	int result;
	result = hap[0];
	while (idx < one + two + thr)
	{
		if (hap[idx] < hap[idx + 1])
		{
			result = idx + 1;
		}
		idx++;
	}
	printf("%d", result);
}