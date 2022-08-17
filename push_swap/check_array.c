/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:49:16 by changkim          #+#    #+#             */
/*   Updated: 2022/08/17 23:57:07 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ps_check_limit(char *word)
{
	long long	tmp;

	tmp = ps_atoi_ll(word);
	if (tmp > 2147483647 || tmp < -2147483648)
		return (0);
	return (1);
}

void	ps_check_duplicate(int *array, int array_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size)
	{
		j = i + 1;
		while (j < array_size)
		{
			if (array[j] == array[i])
			{
				free(array);
				ps_print_error("arg is duplicated");
			}
			j++;
		}
		i++;
	}
}

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
		if (str[i] == '-' && ps_str_check_from_n(str, 1) > 0)
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

int	ps_str_check_from_n(char *str, int n)
{
	int	i;

	i = n;
	while (i < (int)ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		i++;
	}
	if (i == n)
		return (-1);
	return (1);
}
