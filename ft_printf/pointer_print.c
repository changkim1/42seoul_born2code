/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:30:01 by changkim          #+#    #+#             */
/*   Updated: 2022/05/19 18:14:41 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *pt)
{
	uintptr_t 	ptr;
	int			count;

	ptr = (uintptr_t)pt;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
		count += print_pointer_hex(ptr);
	return (count);
}

int	print_pointer_hex(uintptr_t n)
{
	char		*hex;
	int			count;
	uintptr_t	tmp;

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
	ft_puthex_pointer(tmp, count, hex);
	return (count);
}

void	ft_puthex_pointer(uintptr_t n, int count, char *hex)
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
