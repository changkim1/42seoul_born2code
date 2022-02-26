#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long long	N;

	long long	*ogak;
	long long	*hap;
	
	scanf("%lld", &N);
	ogak = (long long *)malloc(sizeof(long long) * (N + 1));
	hap = (long long *)malloc(sizeof(long long) * (N + 1));
	ogak[0] = 1;
	hap[0] = 1;
	long long i;
	i = 1;
	while (i <= N)
	{
		hap[i] = hap[i - 1] + 3;
		i++;
	}
	i = 1;
	while (i <= N)
	{
		ogak[i] = ogak[i - 1] + hap[i];
		i++;
	}
	i = 0;
	printf("%lld\n", (ogak[N] % 45678));
}