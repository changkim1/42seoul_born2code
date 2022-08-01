/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:11:33 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 22:24:57 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// ps double check 함수에서 oper_set 의 마지막 원소 하나가 남음. 이거 하나 마지막에 처리 해줘야함.
void	ps_sort(t_stack *stack, int *array, int array_size)
{
	stack->oper_set = (char **)malloc(sizeof(char *) * 4);
	if (!stack->oper_set)
		exit(1);
	if (stack->a_size > 3)
	{
		ps_node_to_stack_3_way(array, array_size, stack);
	}
	if (stack->oper_set[0])
	{
		write(1, stack->oper_set[0], ft_strlen(stack->oper_set[0]));
		write(1, "\n", 1);
	}
}

void	ps_node_to_stack_3_way(int *array, int array_size, t_stack *stack)
{
	t_pivot	pivot;
	int	i;

	i = array_size;
	pivot = ps_make_pivot(array, array_size);
	while (i > 0)
	{
		stack = ps_move_node_3_way(&pivot, stack);
		i--;
	}
}

t_stack	*ps_move_node_3_way(t_pivot *pivot, t_stack *stack)
{
	if (stack->a_top->content > pivot->big)
	{
		ps_ra(stack);
	}
	else if (stack->a_top->content < pivot->small)
	{
		ps_pb(stack);
		ps_rb(stack);
	}
	else
	{
		ps_pb(stack);
	}
	return (stack);
}