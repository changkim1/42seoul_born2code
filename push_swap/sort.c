/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:11:33 by changkim          #+#    #+#             */
/*   Updated: 2022/08/03 23:14:57 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_sort(t_stack *stack, int *array, int array_size)
{
	stack->oper_set = (char **)malloc(sizeof(char *) * 4);
	if (!stack->oper_set)
		exit(1);
	if (stack->a_size == 2)
	{
		if (stack->a_top->content > stack->a_top->next->content)
			ps_sa(stack);
	}
	else if (stack->a_size == 3)
		ps_sort_three_arg(stack->a_top, stack);
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

void	ps_sort_over_three(t_stack *stack)
{
	t_loc	loc;

	while (stack->a_size > 3)
		ps_pb(stack);
	if (stack->a_size == 2)
	{
		if (stack->a_top->content > stack->a_top->next->content)
			ps_sa(stack);
	}
	else if (stack->a_size == 3)
		ps_sort_three_arg(stack->a_top, stack);
	while (stack->b_size > 0)
	{
		loc.tmp_a = 0;
		loc.tmp_b = 0;
		ps_make_real_loc(stack, &loc);
		ps_sort_move(stack, &loc);
	}
	ps_sort_last(stack, &loc);
}

void	ps_sort_last(t_stack *stack, t_loc *loc)
{
	int	last_a;

	ps_where_min_a(stack, loc);
	last_a = loc->min_a;
	if (last_a >= (stack->a_size + 1) / 2)
		last_a = (stack->a_size - last_a) * (-1);
	while (last_a != 0)
		last_a = ps_sort_move_a(stack, last_a);
}