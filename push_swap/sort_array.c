/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:44:13 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/31 15:07:55 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	ps_make_pivot(int *array, int array_size);

void	ps_bubble_sort(int *array, int array_size)
{
	int	i;
	int	j;
	int	swap;

	i = array_size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[j + 1])
			{
				swap = array[j];
				array[j] = array[j + 1];
				array[j + 1] = swap;
			}
			j++;
		}
		i--;
	}
}