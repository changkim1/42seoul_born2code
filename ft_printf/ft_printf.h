#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	check_format(char type, va_list vl);
int	ft_printf(const char *format, ...);

int	c(char a);
int	s(char *str);
int d(int n);
int u(int n);

int x(int n);
int X(int n);

void	ft_putnbr(int n, char *str, int count);
void	ft_putnbr_u(unsigned int n, char *str, int count);
void	make_hex(char *str, char checker);
void	ft_puthex(unsigned int n, char *str, int count, char *hex);
