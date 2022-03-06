#include <stdio.h>
#include <stdlib.h>

typedef struct jwapyo {
	int x;
	int y;
} jwapyo;

int	compare(const void *a, const void *b)
{
	if (((jwapyo *)a)->x > ((jwapyo *)b)->x)
		return (1);
	if (((jwapyo *)a)->x < ((jwapyo *)b)->x)
		return (-1);
	if (((jwapyo *)a)->x == ((jwapyo *)b)->x)
	{
		if (((jwapyo *)a)->y > ((jwapyo *)b)->y)
			return (1);
		if (((jwapyo *)a)->y < ((jwapyo *)b)->y)
			return (-1);
	}
	return (0);
}


int main(void)
{
	int n;
	scanf("%d", &n);
	jwapyo jwapyos[n];
	int i = 0;
	while (i < n)
	{
		scanf("%d %d", &jwapyos[i].x, &jwapyos[i].y);
		i++;
	}
	qsort(jwapyos, n, sizeof(jwapyo), compare);
	i = 0;
	while (i < n)
	{
		printf("%d %d\n", jwapyos[i].x, jwapyos[i].y);
		i++;
	}
}