/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:11:33 by changkim          #+#    #+#             */
/*   Updated: 2022/08/04 23:11:49 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_sort(t_stack *stack, int *array, int array_size)
{
	if (stack->a_size == 2)
	{
		if (stack->a_top->content > stack->a_top->next->content)
			ps_sa(stack);
	}
	else if (stack->a_size == 3)
		ps_sort_three_arg(stack->a_top, stack);
	else if (stack->a_size == 5)
		ps_sort_five_arg(stack, array);
	else if (stack->a_size > 3)
	{
		ps_node_to_stack_3_way(array, array_size, stack);
		ps_sort_over_three(stack);
	}
}

void	ps_sort_three_arg(t_node *node, t_stack *stack)
{
	t_node	*tmp;
	int	one;
	int	two;
	int	three;

	tmp = node->next;
	one = tmp->prev->content;
	two = tmp->content;
	three = tmp->next->content;
	if (one > two && two < three && one > three)
		ps_ra(stack);
	else if (one > two && two > three)
	{
		ps_sa(stack);
		ps_rra(stack);
	}
	else if (one > two && two < three && three > one)
		ps_sa(stack);
	else if (one < two && two > three && three < one)
		ps_rra(stack);
	else if (one < two && two > three && three > one)
	{
		ps_rra(stack);
		ps_sa(stack);
	}
}

void	ps_sort_five_arg(t_stack *stack, int *array)
{
	int	pivot;

	pivot = array[2];
	while (stack->a_size > 3)
	{
		if (stack->a_top->content < pivot)
			ps_pb(stack);
		else
			ps_ra(stack);
	}
	ps_sort_three_arg(stack->a_top, stack);
	if (stack->b_top->content < stack->b_top->next->content)
		ps_sb(stack);
	while (stack->b_size > 0)
		ps_pa(stack);
}