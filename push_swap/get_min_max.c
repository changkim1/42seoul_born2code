/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:20:21 by changkim          #+#    #+#             */
/*   Updated: 2022/08/03 23:06:07 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_what_min_max(t_node *node, char *min_or_max)
{
	int		res;

	res = node->content;

	if (ft_strcmp(min_or_max, "min") == 0)
	{		
	
		while (node != 0)
		{
			if (res > node->content)
				res = node->content;
			node = node->next;
		}
	}
	else if (ft_strcmp(min_or_max, "max") == 0)
	{
		while (node != 0)
		{
			if (res < node->content)
				res = node->content;
			node = node->next;
		}
	}
	return (res);
}

void	ps_where_min_a(t_stack *stack, t_loc *loc)
{
	int		i;
	int		min_a;
	t_node	*node_a;

	i = 0;
	node_a = stack->a_top;
	min_a = ps_what_min_max(node_a, "min");
	while (i < stack->a_size)
	{
		if (min_a == node_a->content)
		{
			loc->min_a = i;
			break ;
		}
		node_a = node_a->next;
		i++;
	}

}

void	ps_where_min_b(t_stack *stack, t_loc *loc)
{
	int		i;
	int		min_b;
	t_node	*node_b;

	i = 0;
	node_b = stack->a_top;
	min_b = ps_what_min_max(node_b, "min");
	while (i < stack->a_size)
	{
		if (min_b == node_b->content)
		{
			loc->min_b = i;
			return ;
		}
		node_b = node_b->next;
		i++;
	}
}

