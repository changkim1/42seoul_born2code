#include <stdio.h>

int prime_f(int nb)
{
	unsigned int	i;

	i = 2;
	if (nb == 2)
		return (1);
	if (nb <= 1)
		return (0);
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int n_prime_f(int nb)
{
	int	result;

	result = nb;
	if (nb <= 2)
		return (2);
	while (!prime_f(result))
	{
		result++;
	}
	return (result);
}

int main(void)
{
	printf("%d\n", n_prime_f(3));
	printf("%d\n", n_prime_f(2147483645));
}