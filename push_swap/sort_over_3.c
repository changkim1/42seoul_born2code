/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_over_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 23:03:10 by changkim          #+#    #+#             */
/*   Updated: 2022/08/04 23:03:42 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	loc->real_a = last_a;
	while (loc->real_a != 0)
		ps_sort_move_a(stack, loc);
}