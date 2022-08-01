#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"

int main(void)
{
	char *str;

	str = ft_strdup("Abc");
	printf("%s\n", str);
	ft_memset(str, 'a', ft_strlen(str));
	printf("%s\n", str);
}