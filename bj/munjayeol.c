#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *a, *b;
	a = (char *)calloc(1, 51);
	b = (char *)calloc(1, 51);
	scanf("%s%s", a, b);

	int i = 0;
	int j = 0;
	int a_len = strlen(a);
	int b_len = strlen(b);
	
}