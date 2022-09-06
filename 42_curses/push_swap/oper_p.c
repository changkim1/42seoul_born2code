/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:00:54 by changkim          #+#    #+#             */
/*   Updated: 2022/08/18 02:28:25 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ps_pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->b_size == 0)
		return ;
	tmp = stack->b_top;
	if (stack->b_size >= 2)
	{
		stack->b_top = tmp->next;
		stack->b_top->prev = NULL;
	}
	if (stack->a_size == 0)
	{
		tmp->next = NULL;
		stack->a_top = tmp;
		stack->a_bot = tmp;
	}
	else
	{
		tmp->next = stack->a_top;
		stack->a_top->prev = tmp;
		stack->a_top = tmp;
	}
	ps_resize_p(stack, 'a');
	write(1, "pa\n", 3);
}

void	ps_pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->a_size == 0)
		return ;
	tmp = stack->a_top;
	if (stack->a_size >= 2)
	{
		stack->a_top = tmp->next;
		stack->a_top->prev = NULL;
	}	
	if (stack->b_size == 0)
	{
		tmp->next = NULL;
		stack->b_top = tmp;
		stack->b_bot = tmp;
	}
	else
	{
		tmp->next = stack->b_top;
		stack->b_top->prev = tmp;
		stack->b_top = tmp;
	}
	ps_resize_p(stack, 'b');
	write(1, "pb\n", 3);
}

void	ps_resize_p(t_stack *stack, char checker)
{
	if (checker == 'a')
	{
		stack->a_size++;
		stack->b_size--;
	}
	else
	{
		stack->a_size--;
		stack->b_size++;
	}
}
