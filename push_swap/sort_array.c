/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:44:13 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/15 16:38:27 by zzankor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	ps_make_pivot(int *array, int w_count);

int	*ps_bubble_sort(int *array, int w_count)
{
	int	i;
	int	j;
	int	swap;

	i = w_count - 1;
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
	return (array);
}