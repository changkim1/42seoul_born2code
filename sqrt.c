#include <stdio.h>

int	sqrt_z(int nb)
{
	unsigned int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

int main(void)
{
	printf("%u\n", sqrt_z(2147483647));
}