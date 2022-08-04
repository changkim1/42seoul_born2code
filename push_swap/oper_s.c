/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:15:53 by changkim          #+#    #+#             */
/*   Updated: 2022/08/04 22:58:29 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(t_stack *stack)
{
	int	tmp;

	if (stack->a_size < 2)
		return ;
	else
	{
		tmp = stack->a_top->content;
		stack->a_top->content = stack->a_top->next->content;
		stack->a_top->next->content = tmp;
	}
	write(1, "sa\n", 3);
}

void	ps_sb(t_stack *stack)
{
	int	tmp;

	if (stack->b_size < 2)
		return ;
	else
	{
		tmp = stack->b_top->content;
		stack->b_top->content = stack->b_top->next->content;
		stack->b_top->next->content = tmp;
	}
	write(1, "sb\n", 3);
}
