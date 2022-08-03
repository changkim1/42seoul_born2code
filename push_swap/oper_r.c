/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:25:32 by changkim          #+#    #+#             */
/*   Updated: 2022/08/03 23:14:29 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_ra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_top;
	stack->a_top = stack->a_top->next;
	stack->a_top->prev = NULL;
	stack->a_bot->next = tmp;
	tmp->prev = stack->a_bot;
	stack->a_bot = tmp;
	stack->a_bot->next = NULL;
	write(1, "ra\n", 3);
}

void	ps_rb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_top;
	stack->b_top = stack->b_top->next;
	stack->b_top->prev = NULL;
	stack->b_bot->next = tmp;
	tmp->prev = stack->b_bot;
	stack->b_bot = tmp;
	stack->b_bot->next = NULL;
	write(1, "rb\n", 3);
}
