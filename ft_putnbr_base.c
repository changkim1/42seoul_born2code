#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (base[i])
	{
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
		j = i + 1;
	}
	if (i == 0 || i == 1)
		return (0);
	return (1);
}

void	make_base(unsigned int nbr1, char *base)
{
	int i;
	int base_size;
	char base_nbr[33];

	base_nbr[0] = 0;
	i = 0;
	base_size = 0;
	while (base[base_size])
		base_size++;
	if (nbr1 == 0)
		write(1, &base[0], 1);
	while (nbr1 > 0)
	{
		base_nbr[i] = base[nbr1 % base_size];
		nbr1 /= base_size;
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		ft_putchar(base_nbr[i]);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nbr1;

	nbr1 = 1;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr1 = -nbr;
			ft_putchar('-');
		}
		else
			nbr1 = nbr;
		make_base(nbr1, base);
	}
}

int main(void)
{
	ft_putnbr_base(-10, "01234567");
	printf("\n");
	ft_putnbr_base(0, "01234567");
	printf("\n");
	ft_putnbr_base(-2147483648, "01234567");
	printf("\n");
	ft_putnbr_base(2147483647, "01234567");
	printf("\n");
	ft_putnbr_base(10, "01");
	printf("\n");
	ft_putnbr_base(0, "01");
	printf("\n");
	ft_putnbr_base(-2147483648, "01");
	printf("\n");
	ft_putnbr_base(1, "poneyvif");
	printf("\n");
	ft_putnbr_base(1, "aa");
	printf("e\n");
	ft_putnbr_base(1, "a+");
	printf("e\n");
	ft_putnbr_base(1, "a");
	printf("e\n");
}