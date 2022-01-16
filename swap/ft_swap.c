#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int array;

	array = *a;
	*a = *b;
	*b = array;
}

void	ft_swap_fault(int a, int b)
{
	int i;

	i = a;
	a = b;
	b = i;
}

int main(void)
{
	int i;
	i = 10;
	int j;
	j = 20;

	int *a;
	a = &i;
	int *b;
	b = &j;
	
	ft_swap(a, b);
	printf("swap = %d %d\n", *a, *b);

	ft_swap_fault(*a, *b);
	printf("fault = %d %d\n", *a, *b);
}