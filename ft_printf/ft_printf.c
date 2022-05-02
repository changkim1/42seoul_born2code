<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:29:55 by changkim          #+#    #+#             */
/*   Updated: 2022/05/02 22:39:15 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
=======
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
>>>>>>> efae69cc60f4c69d0898673e2592ca1cdbd4cfee
#include "ft_printf.h"

int	check_format(char type, va_list vl)
{
<<<<<<< HEAD
	int	ret;

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
		ret = print_low_hex(va_arg(vl, int));
	else if (type == 'X')
		ret = print_upper_hex(va_arg(vl, int));
=======
	int ret;

	if (type == 'c')
		ret = c(va_arg(vl, int));
	else if (type == 's')
		ret = s(va_arg(vl, char *));
	// else if (type == 'p')
	// 	ret = p(va_arg(vl, void *));
	else if (type == 'd')
		ret = d(va_arg(vl, int));
	else if (type == 'i')
		ret = i(va_arg(vl, int));
	else if (type == 'u')
		ret = u(va_arg(vl, int));
	else if (type == 'x')
		ret = x(va_arg(vl, int));
	else if (type == 'X')
		ret = X(va_arg(vl, int));
>>>>>>> efae69cc60f4c69d0898673e2592ca1cdbd4cfee
	else if (type == '%')
		write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
<<<<<<< HEAD
	va_list	vl;
	int		i;
	int		ret;
=======
	va_list vl;
	int i;
	int ret;
	void *content;
>>>>>>> efae69cc60f4c69d0898673e2592ca1cdbd4cfee

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
<<<<<<< HEAD
=======

int main(void)
{
	printf("\n");
	ft_printf("ft = %s %c\n", "abc", 'd');
	printf("pr = %s %c\n", "abc", 'd');
	printf("i = %i\nd = %d\n", 0x10, 11);
	printf("u = %u\n", -2147483647);
	ft_printf("u = %u\n", -2147483647);
	ft_printf("d = %d\n", -2147483647);
	printf("d = %d\n", -2147483647);

	printf("x = %x\n", 128347);
	ft_printf("x = %x\n", 128347);
	printf("X = %X\n", -128347);
	ft_printf("X = %X\n", -128347);

}
>>>>>>> efae69cc60f4c69d0898673e2592ca1cdbd4cfee
