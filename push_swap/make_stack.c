/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 16:33:50 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 19:24:56 by changkim         ###   ########.fr       */
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

t_stack	*ps_get_stack(t_stack *stack_a)
{
	t_node	*new_node;

	new_node = ps_make_new_node();
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_a)
		exit(1);
	stack_a->size = 0;
	stack_a->top = new_node;
	stack_a->bot = new_node;
	return (stack_a);
}

t_stack	*ps_array_to_stack(int *array, int array_size, t_stack *stack_a)
{
	int		i;
	t_node	*new_node;

	i = 0;
	stack_a = ps_get_stack(stack_a);
	while (i < array_size)
	{
		new_node = ps_make_new_node();
		printf("%d %d\n", array[0], i);
		stack_a->bot->content = (int)array[i];
		stack_a->bot->next = new_node;
		new_node->prev = stack_a->bot;
		stack_a->bot = new_node;
		stack_a->size++;
		printf("top = %d bot = %d\n", stack_a->top->content, stack_a->bot->prev->content);
		i++;
	}
	stack_a->bot = stack_a->bot->prev;
	free(new_node);
	return (stack_a);
}