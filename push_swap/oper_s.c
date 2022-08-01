/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:15:53 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 22:11:16 by changkim         ###   ########.fr       */
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
	stack->oper_set = ps_put_oper(stack, "sa");
	printf("sa oper_set\n1%s\n2%s\n", stack->oper_set[0], stack->oper_set[1]);
	ps_check_double(stack, "sa", "sb", "ss");
	printf("\nsa oper_set\n1%s\n2%s\n", stack->oper_set[0], stack->oper_set[1]);
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
	stack->oper_set = ps_put_oper(stack, "sb");
	ps_check_double(stack, "sb", "sa", "ss");
}
