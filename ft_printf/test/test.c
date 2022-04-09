#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int i = 1000;
	int count = 0;
	unsigned int n;

	n = i;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	// printf("%X %x\n", 4294967295, -100); // 4294967295 = -1
	printf("%X\n", i); // 4294967295 = -1
	printf("%d\n", count);
	printf("%d %i\n", 0x13, 0x13);
}
