/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 18:51:45 by changkim          #+#    #+#             */
/*   Updated: 2022/08/04 22:46:08 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
void	ps_sort_move(t_stack *stack, t_loc *loc)
{
	while (1)
	{
		ps_sort_move_same(stack, loc);
		ps_sort_move_a(stack, loc);
		ps_sort_move_b(stack, loc);
		if (loc->real_a == 0 && loc->real_b == 0)
			break ;
	}
	ps_pa(stack);
}

void	ps_sort_move_a(t_stack *stack, t_loc *loc)
{
	if (loc->real_a < 0)
	{
		ps_rra(stack);
		loc->real_a++;
	}
	else if (loc->real_a > 0)
	{
		ps_ra(stack);
		loc->real_a--;
	}
	else
		return ;
}

void	ps_sort_move_b(t_stack *stack, t_loc *loc)
{
	if (loc->real_b < 0)
	{
		ps_rrb(stack);
		loc->real_b++;
	}
	else if (loc->real_b > 0)
	{
		ps_rb(stack);
		loc->real_b--;
	}
	else
		return ;
}

void	ps_sort_move_same(t_stack *stack, t_loc *loc)
{
	if (loc->real_a < 0 && loc->real_b < 0)
	{
		ps_rrr(stack);
		loc->real_a++;
		loc->real_b++;
	}
	else if (loc->real_a > 0 && loc->real_b > 0)
	{
		ps_rr(stack);
		loc->real_a--;
		loc->real_b--;
	}
	else
		return ;
}