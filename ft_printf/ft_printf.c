#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int	check_format(char type, va_list vl)
{
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
	else if (type == '%')
		write(1, "%", 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list vl;
	int i;
	int ret;
	void *content;

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
