/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:51:45 by changkim          #+#    #+#             */
/*   Updated: 2022/08/03 20:30:05 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort_move(t_stack *stack, t_loc *loc)
{
	int	a_idx;
	int	b_idx;

	a_idx = loc->real_a;
	b_idx = loc->real_b;
	while (1)
	{
		a_idx = ps_sort_move_a(stack, a_idx);
		b_idx = ps_sort_move_b(stack, b_idx);
		if (a_idx == 0 && b_idx == 0)
			break ;
	}
	ps_pa(stack);
}

int	ps_sort_move_a(t_stack *stack, int idx)
{
	if (idx < 0)
	{
		ps_rra(stack);
		idx++;
	}
	else if (idx > 0)
	{
		ps_ra(stack);
		idx--;
	}
	return (idx);
}

int	ps_sort_move_b(t_stack *stack, int idx)
{
	if (idx < 0)
	{
		ps_rrb(stack);
		idx++;
	}
	else if (idx > 0)
	{
		ps_rb(stack);
		idx--;
	}
	return (idx);
}

