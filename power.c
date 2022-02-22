#include <stdio.h>
#include <unistd.h>

int i_power(int nb, int power)
{
	int result;

	result = 1;
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

int	r_power(int nb, int power)
{
	int result;

	result = 1;
	if (nb < 0)
		return (0);
	if (power == 0)
		return (1);
	result = result * nb;
	return (result * r_power(nb, power - 1));
}

int  main(void)
{
	printf("%d\n", i_power(3, 3));
	printf("%d\n", i_power(0, 0));
	printf("%d\n", i_power(1, 0));
	printf("%d\n", r_power(2, 5));
}