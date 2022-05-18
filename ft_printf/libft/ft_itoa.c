/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:10 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 15:57:14 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	how_many_tens(long long int n)
{
	int	num;

	num = 0;
	if (n <= 0)
	{
		n *= -1;
		num++;
	}
	while (n > 0)
	{
		n /= 10;
		num++;
	}
	return (num);
}

char	*ft_itoa(int n)
{
	int				i;
	long long int	cp_n;
	char			*str;

	cp_n = (long long int)n;
	i = how_many_tens(cp_n);
	str = (char *)malloc(sizeof(char) * i + 1);
	if (!str)
		return (0);
	str[i] = 0;
	if (cp_n < 0)
		cp_n *= -1;
	while (--i >= 0)
	{
		str[i] = cp_n % 10 + '0';
		cp_n /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
