/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 14:49:16 by changkim          #+#    #+#             */
/*   Updated: 2022/07/31 15:30:34 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
