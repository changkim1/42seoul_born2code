/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:25 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/15 15:51:40 by zzankor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*array;
	int	w_count;

	if (ac == 1)
		return (0);
	w_count = ps_count_word(ac, av);
	array = ps_make_array(ac, av, w_count, array);
	ps_check_duplicate(array, w_count);
	array = ps_bubble_sort(array, w_count);
	for (int i = 0; i < w_count; i++)
		printf("%d ", array[i]);
	printf("\n");
}