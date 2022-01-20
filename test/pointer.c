#include <stdio.h>

int main(void)
{
	char *str;
	int i;

	i = 0;
	str[5] = 0;
	while (str[i])
	{
		str[i] = 1;
		i++;
	}
	printf("%s\n", str);
	return 0;
}