/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:33:50 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 21:36:41 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_make_new_node(void)
{
	t_node	*new_node;

	new_node = (void *)0;
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->content = 0;
	new_node->next = (void *)0;
	new_node->prev = (void *)0;
	return (new_node);
}

t_stack	*ps_get_stack(t_stack *stack)
{
	t_node	*new_node;

	new_node = ps_make_new_node();
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit(1);
	stack->a_size = 0;
	stack->a_top = new_node;
	stack->a_bot = new_node;
	stack->b_size = 0;
	return (stack);
}

t_stack	*ps_array_to_stack(int *array, int array_size, t_stack *stack)
{
	int		i;
	t_node	*new_node;

	i = 0;
	stack = ps_get_stack(stack);
	while (i < array_size)
	{
		new_node = ps_make_new_node();
		stack->a_bot->content = (int)array[i];
		stack->a_bot->next = new_node;
		new_node->prev = stack->a_bot;
		stack->a_bot = new_node;
		stack->a_size++;
		i++;
	}
	stack->a_bot = stack->a_bot->prev;
	free(new_node);
	return (stack);
}