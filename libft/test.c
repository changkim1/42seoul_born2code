#include "libft.h"
#include <stdio.h>
#include <memory.h>

int main(void)
{
	int arr[1000];
	memset(arr, 0x2f, sizeof(int)*1000);
	printf("%d\n", arr[0]);
}