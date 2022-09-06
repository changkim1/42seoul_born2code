/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:29:45 by changkim          #+#    #+#             */
/*   Updated: 2022/05/02 22:40:27 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_low_hex(unsigned int n)
{
	char			*hex;
	int				count;
	unsigned int	tmp;

	tmp = n;
	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	hex = (char *)malloc(17);
	if (!hex)
		return (0);
	make_hex(hex, 'x');
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	tmp = n;
	ft_puthex(tmp, count, hex);
	return (count);
}

int	print_upper_hex(unsigned int n)
{
	char			*hex;
	int				count;
	unsigned int	tmp;

	tmp = n;
	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	hex = (char *)malloc(17);
	make_hex(hex, 'X');
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	tmp = n;
	ft_puthex(tmp, count, hex);
	return (count);
}

void	make_hex(char *str, char checker)
{
	int		i;
	char	c;

	i = 0;
	if (checker == 'x')
		c = 'a';
	else if (checker == 'X')
		c = 'A';
	while (i < 10)
	{
		str[i] = i + '0';
		i++;
	}
	while (i < 16)
	{
		str[i] = c;
		i++;
		c++;
	}
	str[i] = 0;
}

void	ft_puthex(unsigned int n, int count, char *hex)
{
	int		i;
	char	*str;

	str = (char *)malloc(count + 1);
	if (!str)
		return ;
	i = count;
	str[i] = 0;
	i--;
	while (n > 0)
	{
		str[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	write(1, str, count);
	free(str);
	free(hex);
}
