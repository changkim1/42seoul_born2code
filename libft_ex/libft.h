#ifndef LIBFT_H
# define LIBFT_H

int	ft_atoi(const char *str);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int i);
int ft_isprint(int c);
int ft_strlen(char *str);
void	*ft_memset(void *dest, int value, size_t count);

#include <string.h>

#endif