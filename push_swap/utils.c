/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:14:34 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/31 15:25:43 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ps_atoi_ll(char *str)
{
	int			i;
	int			len;
	long long	tmp;
	long long	ten;

	tmp = 0;
	ten = 1;
	len = ft_strlen(str);
	i = len - 1;
	while (i >= 0)
	{
		if (str[i] == '-')
		{
			tmp *= -1;
			return (tmp);
		}
		if (!ft_isdigit(str[i]))
			ps_print_error("arg is not integer");
		tmp = tmp + ten * (str[i] - '0');
		ten *= 10;
		i--;
	}
	return (tmp);
}