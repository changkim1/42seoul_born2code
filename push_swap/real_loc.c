/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_loc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:02:06 by changkim          #+#    #+#             */
/*   Updated: 2022/08/04 22:58:11 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_make_real_loc(t_stack *stack, t_loc *loc)
{
	t_node	*b_node;
	t_loc	tmp;
	int		b_num;
	int		i;

	b_node = stack->b_top;
	i = 0;
	loc->real_a = 0;
	loc->real_b = 0;
	while (i < stack->b_size)
	{
		b_num = b_node->content;
		ps_make_a_idx(stack, loc, b_num); // tmp_a 완성
		if (i >= (stack->b_size + 1) / 2)
			loc->tmp_b = (stack->b_size - i) * (-1);
		else
			loc->tmp_b = i;
		tmp = ps_loc_cpy(loc);
		if (ps_change_to_small(&tmp, i) == 1)
		{
			loc->real_a = loc->tmp_a;
			loc->real_b = loc->tmp_b;
		}
		b_node = b_node->next;
		i++;
	}
}

void	ps_make_a_idx(t_stack *stack, t_loc *loc, int b_num)
{
	int	min_a;
	int	max_a;

	min_a = 0;
	max_a = 0;

	if (stack->a_size <= 1)
	{
		min_a = stack->a_top->content;
		max_a = stack->a_top->content;
	}
	else
	{
		min_a = ps_what_min_max(stack->a_top, "min");
		max_a = ps_what_min_max(stack->a_top, "max");
	}
	if (b_num < min_a)
		ps_make_a_idx_min_max(stack, loc, "min");
	else if (b_num > max_a)
		ps_make_a_idx_min_max(stack, loc, "max");
	else
		ps_make_a_idx_mid(stack, loc, b_num);
}

void	ps_make_a_idx_min_max(t_stack *stack, t_loc *loc, char *max_or_min)
{
	int	tmp_loc;

	if (stack->a_size <= 1)
	{
		loc->min_a = 0;
		return ;
	}
	ps_where_min_a(stack, loc);
	ps_where_max_a(stack, loc);
	tmp_loc = loc->min_a;
	if (ft_strcmp(max_or_min, "max") == 0)
		tmp_loc = loc->max_a + 1;
	if (tmp_loc >= (stack->a_size + 1) / 2)
		tmp_loc = (stack->a_size - tmp_loc) * (-1);
	loc->tmp_a = tmp_loc;
}

void	ps_make_a_idx_mid(t_stack *stack, t_loc *loc, int b_num)
{
	t_node	*node;
	int		tmp_loc;
	
	tmp_loc = 1;
	node = stack->a_top;
	while (node->next != 0)
	{
		if (b_num > node->content && b_num < node->next->content)
			break ;
		node = node->next;
		tmp_loc++;
	}
	if (tmp_loc >= (stack->a_size + 1) / 2)
		tmp_loc = (stack->a_size - tmp_loc) * (-1);
	loc->tmp_a = tmp_loc;
}

int	ps_change_to_small(t_loc *loc, int idx)
{
	if (loc->tmp_a < 0)
		loc->tmp_a *= -1;
	if (loc->tmp_b < 0)
		loc->tmp_b *= -1;
	if (loc->real_a < 0)
		loc->real_a *= -1;
	if (loc->real_b < 0)
		loc->real_b *= -1;
	if (idx == 0 || loc->real_a + loc->real_b > loc->tmp_a + loc->tmp_b)
		return (1);
	else
		return (0);
}