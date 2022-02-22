#include <stdio.h>
#include <math.h>

int N, c, r;
long long int result;

void solve(int N, int c, int r)
{
	if (N == 0)
		return ;
	long long int size;
	size = (long long int)pow((double)2, (double)N);
	long long int half = size / 2;
	if (r / half == 0 && c / half == 0)
	{
		result += half * half * 0;
		solve(N - 1, c % half, r % half);
	}
	else if (r / half == 0 && c / half == 1)
	{
		result += half * half * 1;
		solve(N - 1, c % half, r % half);
	}
	else if (r / half == 1 && c / half == 0)
	{
		result += half * half * 2;
		solve(N - 1, c % half, r % half);
	}
	else if (r / half == 1 && c / half == 1)
	{
		result += half * half * 3;
		solve(N - 1, c % half, r % half); // c -> 7 % 4 == 3
	}
}

int main(void)
{
	scanf("%d%d%d", &N, &r, &c);
	solve(N, c, r);
	printf("%lld", result);
}