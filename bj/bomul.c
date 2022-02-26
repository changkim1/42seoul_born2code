#include <stdio.h>

int main(void)
{
	int N;
	scanf ("%d", &N);
	int A[N];
	int B[N];
	int B_i[N];
	int A_i[N];
	int A_p[N];
	int B_p[N];

	int i = 0;
	while (i < N)
	{
		scanf("%d", &A[i]);
		A_p[i] = A[i];
		i++;
	}
	i = 0;
	while (i < N)
	{
		scanf("%d", &B[i]);
		B_p[i] = B[i];
		i++;
	}
	i = 0;
	while (i < N)
	{
		B_i[i] = i;
		A_i[i] = i;
		i++;
	}
	int count = 0;
	i = 0;
	int tmp = 0;
	int tmp_i = 0;
	while (count < N - 1)
	{
		i = 0;
		while (i < N - 1)
		{
			if (B[i] > B[i + 1])
			{
				tmp = B[i];
				tmp_i = B_i[i];
				B[i] = B[i + 1];
				B_i[i] = B_i[i + 1];
				B[i + 1] = tmp;
				B_i[i + 1] = tmp_i;
			}
			i++;
		}
		count++;
	}
	i = 0;
	count = 0;
	tmp = 0;
	tmp_i = 0;
	while (count < N - 1)
	{
		i = 0;
		while (i < N - 1)
		{
			if (A[i] < A[i + 1])
			{
				tmp = A[i];
				tmp_i = A_i[i];
				A[i] = A[i + 1];
				A_i[i] = A_i[i + 1];
				A[i + 1] = tmp;
				A_i[i + 1] = tmp_i;
			}
			i++;
		}
		count++;
	}
	i = 0;
	while (i < N)
	{
		A[B_i[i]] = A_p[A_i[i]];
		i++;
	}
	i = 0;
	int result = 0;
	while (i < N)
	{
		result += A[i] * B_p[i];
		i++;
	}
	printf("%d", result);
}