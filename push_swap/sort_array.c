/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:44:13 by zzankor           #+#    #+#             */
/*   Updated: 2022/08/04 19:48:04 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	ps_make_pivot(int *array, int array_size)
{
	t_pivot	pivot;

	pivot.big = array[array_size / 3];
	pivot.small = array[array_size / 3 * 2];
	return (pivot);
}

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