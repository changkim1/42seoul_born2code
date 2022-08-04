/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:25 by zzankor           #+#    #+#             */
/*   Updated: 2022/08/05 00:14:10 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_stack	*stack;
	int		*array;
	int		array_size;

	stack = (void *)0;
	if (ac < 2)
		return (0);
	array_size = ps_check_array_size(av, ac);
	array = (int *)malloc(sizeof(int) * array_size);
	if (!array)
		exit(1);
	array = ps_make_array(av, ac, array, array_size);
	stack = ps_array_to_stack(array, array_size, stack);
	ps_bubble_sort(array, array_size);
	ps_sort(stack, array, array_size);
	free(array);
	ps_free_stack(stack);
}
