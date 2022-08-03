/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:04:37 by changkim          #+#    #+#             */
/*   Updated: 2022/08/03 21:44:16 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_node_to_stack_3_way(int *array, int array_size, t_stack *stack)
{
	t_pivot	pivot;
	int	i;

	i = array_size;
	pivot = ps_make_pivot(array, array_size);
	while (i > 0)
	{
		stack = ps_move_node_3_way(&pivot, stack);
		i--;
	}
}

t_stack	*ps_move_node_3_way(t_pivot *pivot, t_stack *stack)
{
	if (stack->a_top->content > pivot->big)
		ps_ra(stack);
	else if (stack->a_top->content < pivot->small)
	{
		ps_pb(stack);
		ps_rb(stack);
	}
	else
		ps_pb(stack);
	return (stack);
}
