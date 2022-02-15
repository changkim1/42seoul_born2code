#include <stdio.h>

int main(void)
{
	int a1, b1;
	
	while (1)
	{
		scanf("%d%d", &a1, &b1);
		if (a1 && b1)
			printf("%s\n", (a1 > b1) ? "Yes" : "No");
		else
			break ;
	}
	return (0);
}