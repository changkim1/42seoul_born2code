/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 23:32:58 by changkim          #+#    #+#             */
/*   Updated: 2022/08/05 00:24:02 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_rra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a_size < 2)
		return ;
	tmp = stack->a_bot;
	stack->a_bot = stack->a_bot->prev;
	stack->a_bot->next = NULL;
	stack->a_top->prev = tmp;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	stack->a_top->prev = NULL;
	write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b_size < 2)
		return ;
	tmp = stack->b_bot;
	stack->b_bot = stack->b_bot->prev;
	stack->b_bot->next = NULL;
	stack->b_top->prev = tmp;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	stack->b_top->prev = NULL;
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a_size < 2 || stack->b_size < 2)
		return ;
	tmp = stack->a_bot;
	stack->a_bot = stack->a_bot->prev;
	stack->a_bot->next = NULL;
	stack->a_top->prev = tmp;
	tmp->next = stack->a_top;
	stack->a_top = tmp;
	stack->a_top->prev = NULL;
	tmp = stack->b_bot;
	stack->b_bot = stack->b_bot->prev;
	stack->b_bot->next = NULL;
	stack->b_top->prev = tmp;
	tmp->next = stack->b_top;
	stack->b_top = tmp;
	stack->b_top->prev = NULL;
	write(1, "rrr\n", 4);
}
