/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:30:01 by changkim          #+#    #+#             */
/*   Updated: 2022/05/02 22:39:30 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *pt)
{
	size_t	ptr;
	int		count;

	ptr = (size_t)pt;
	count = 0;
	write(1, "0x", 2);
	count += 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		count++;
	}
	else
		print_low_hex(ptr);
	return (count);
}
