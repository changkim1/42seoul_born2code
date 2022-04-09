#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int	c(char a)
{
	int ret;

	ret = 1;
	write(1, &a, 1);
	return (ret);
}

int	s(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	check_format(char type, va_list vl)
{
	int ret;

	ret = 0;
	if (type == 'c')
		ret = c(va_arg(vl, int));
	else if (type == 's')
		ret = s(va_arg(vl, char *));
	// else if (type == 'p')
	// 	p(content);
	// else if (type == 'd')
	// 	d(content);
	// else if (type == 'i')
	// 	i(content);
	// else if (type == 'u')
	// 	u(content);
	// else if (type == 'x')
	// 	x(content);
	// else if (type == 'X')
	// 	X(content);
	// else if (type == '%')
	// 	write(1, "%", 1);
	// return ;
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
	printf("ft_printf = %d\n", ft_printf("%c %s\n", 'x', "abc"));
	printf("printf =    %d\n", printf("%c %s\n", 'x', "abc"));
}
