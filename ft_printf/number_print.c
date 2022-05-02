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
	char	*str;

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
	str = (char *)malloc(count + 1);
	ft_putnbr(n, str, count);
	return (count);
}

int	print_unsigned(int n)
{
	unsigned int	tmp;
	char			*str;
	int				count;

	count = 0;
	tmp = n;
	while (tmp > 0)
	{
		tmp /= 10;
		count++;
	}
	str = (char *)malloc(count + 1);
	tmp = n;
	ft_putnbr_u(tmp, str, count);
	return (count);
}

void	ft_putnbr(int n, char *str, int count)
{
	int	i;

	i = count;
	str[i] = 0;
	i--;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
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

void	ft_putnbr_u(unsigned int n, char *str, int count)
{
	int	i;

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
