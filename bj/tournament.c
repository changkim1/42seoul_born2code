#include <stdlib.h>
#include <stdio.h>
#define min(a, b) (a < b ? a : b)

int	tournament(int n, int im, int kim, int count)
{
	if (min(im, kim) % 2 == 1 && abs(im - kim) == 1)
		return (count);
	else
	{
		n = (n % 2 == 0 ? n / 2 : (n / 2) + 1);
		im = (im % 2 == 0 ? im / 2 : (im / 2) + 1);
		kim = (kim % 2 == 0 ? kim / 2 : (kim / 2) + 1);
		count++;
		return (tournament(n, im, kim, count));
	}
}

int main(void)
{
	int n, im, kim;
	scanf("%d%d%d", &n, &im, &kim);
	int count = 1;
	count = tournament(n, im, kim, count);
	printf("%d", count);
}