/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:29:49 by changkim          #+#    #+#             */
/*   Updated: 2022/05/02 22:41:29 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_numb(int n)
{
	int		tmp;
	int		count;

	count = 0;
	tmp = n;
	if (n < 0)
	{
		count++;
		tmp *= -1;
	}
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	if (n == 0 || n == -2147483648)
		count = zero_and_minus(n);
	else
		ft_putnbr(n, count);
	return (count);
}

int	print_unsigned(int n)
{
	unsigned int	tmp;
	int				count;

	count = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	if (n == 0)
		count = zero_and_minus(n);
	else
	{
		tmp = n;
		ft_putnbr_u(tmp, count);
	}
	return (count);
}

void	ft_putnbr(int n, int count)
{
	int		i;
	char	*str;

	str = (char *)malloc(count + 1);
	i = count;
	str[i] = 0;
	i--;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	write(1, str, count);
	free(str);
}

void	ft_putnbr_u(unsigned int n, int count)
{
	int		i;
	char	*str;

	str = (char *)malloc(count + 1);
	i = count;
	str[i] = 0;
	i--;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	write(1, str, count);
	free(str);
}

int	zero_and_minus(int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		count = 1;
	}
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	return (count);
}
