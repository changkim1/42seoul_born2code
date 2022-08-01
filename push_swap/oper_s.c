/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:15:53 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 19:30:54 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sa(char **oper_set, t_stack *stack_a)
{
	int	tmp;

	if (stack_a->size < 2)
	{
		return ;
	}
	else
	{
		tmp = stack_a->top->content;
		stack_a->top->content = stack_a->top->next->content;
		stack_a->top->next->content = tmp;
	}
	oper_set = ps_put_oper(oper_set, "sa");
	ps_check_double(oper_set, "sa", "sa", "ss");
}

void	ps_sb(char **oper_set, t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size < 2)
		return ;
	else
	{
		tmp = stack_b->top->content;
		stack_b->top->content = stack_b->top->next->content;
		stack_b->top->next->content = tmp;
	}
	oper_set = ps_put_oper(oper_set, "sb");
	ps_check_double(oper_set, "sb", "sa", "ss");
}
