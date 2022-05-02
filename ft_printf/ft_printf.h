<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 22:29:43 by changkim          #+#    #+#             */
/*   Updated: 2022/05/02 22:37:35 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		check_format(char type, va_list vl);
int		ft_printf(const char *format, ...);

int		print_char(char a);
int		print_str(char *str);
int		print_numb(int n);
int		print_unsigned(int n);

int		print_low_hex(int n);
int		print_upper_hex(int n);

int		print_pointer(void *pt);
=======
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
>>>>>>> efae69cc60f4c69d0898673e2592ca1cdbd4cfee

void	ft_putnbr(int n, char *str, int count);
void	ft_putnbr_u(unsigned int n, char *str, int count);
void	make_hex(char *str, char checker);
void	ft_puthex(unsigned int n, char *str, int count, char *hex);
