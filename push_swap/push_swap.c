/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:12:25 by zzankor           #+#    #+#             */
/*   Updated: 2022/08/03 23:16:50 by changkim         ###   ########.fr       */
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
	t_node	*tmp1;
	tmp1 = stack->a_top;
	if (tmp1)
	{
		printf("%p = ", stack->a_top);
		while (tmp1)
		{
			printf("%d ", tmp1->content);
			tmp1 = tmp1->next;
		}
	}
	printf("\n");
}