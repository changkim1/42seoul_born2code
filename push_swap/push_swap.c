/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:25 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/31 13:27:45 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	// t_stack	*stack_a;
	int		*array;
	int		array_size;

	if (ac < 2)
		return (0);
	array_size = ps_check_array_size(av, ac);
	array = (int *)malloc(sizeof(int) * array_size);
	if (!array)
		exit(1);
	array = ps_make_array(av, ac, array);
	ps_bubble_sort(array, array_size);
	int i = 0;
	while (i < array_size)
	{
		printf("%d\n", array[i]);
		i++;
	}
	// stack_a = (t_stack *)malloc(sizeof(t_stack));
}