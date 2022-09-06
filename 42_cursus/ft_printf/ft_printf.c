/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:29:55 by changkim          #+#    #+#             */
/*   Updated: 2022/05/02 22:45:30 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(char type, va_list vl)
{
	int	ret;

	ret = 0;
	if (type == 'c')
		ret = print_char(va_arg(vl, int));
	else if (type == 's')
		ret = print_str(va_arg(vl, char *));
	else if (type == 'p')
		ret = print_pointer(va_arg(vl, void *));
	else if (type == 'd' || type == 'i')
		ret = print_numb(va_arg(vl, int));
	else if (type == 'u')
		ret = print_unsigned(va_arg(vl, int));
	else if (type == 'x')
		ret = print_low_hex(va_arg(vl, unsigned int));
	else if (type == 'X')
		ret = print_upper_hex(va_arg(vl, unsigned int));
	else if (type == '%')
	{
		write(1, "%", 1);
		ret++;
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	vl;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(vl, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ret += check_format(format[i], vl);
		}
		else
		{
			write(1, &format[i], 1);
			ret++;
		}
		i++;
	}
	return (ret);
}
