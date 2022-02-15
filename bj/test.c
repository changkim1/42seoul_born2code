#include <stdio.h>

int main(void)
{
	int i;
	unsigned int j;

	printf("int i;\nunsigned int j;\n\n");
	i = -2147483647;
	printf("i = %d\n", i);
	j = i;
	printf("j = i;\nj = %u\n", j);
	j *= -1;
	printf("j * -1 = %u\n\n", j);
	

	i = -2147483647;
	printf("i = %d\n", i);
	j = -i;
	printf("j = -i;\nj = %u\n\n", j);

	i = -2147483647;
	printf("i = %d\n", i);
	j = (unsigned int)i;
	printf("j = (unsigned int)i;\ni = %u\n", i);
	printf("j = %u\n\n", j);
	
}

