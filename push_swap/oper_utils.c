/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:20:45 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 22:00:16 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_put_oper(t_stack *stack, char *oper)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(oper);
	if (stack->oper_set[0] != 0)
		i++;
	stack->oper_set[i] = (char *)malloc(len + 1);
	while (oper[j])
	{
		stack->oper_set[i][j] = oper[j];
		j++;
	}
	stack->oper_set[i][j] = 0;
	return (stack->oper_set);
}

void	ps_memset_oper(t_stack *stack, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		stack->oper_set[i] = NULL;
		i++;
	}
}

void	ps_check_double(t_stack *stack, char *op1, char *op2, char *op_double)
{
	if (stack->oper_set[0] == NULL || stack->oper_set[1] == NULL)
		return ;
	else if (ft_strcmp(stack->oper_set[0], op2) == 0)
	{
		if (ft_strcmp(stack->oper_set[1], op1) == 0)
		{
			write(1, op_double, ft_strlen(op_double));
			write(1, "\n", 1);
		}
	}
	else
	{
		write(1, stack->oper_set[0], ft_strlen(stack->oper_set[0]));
		write(1, "\n", 1);
		ps_memset_oper(stack, 2);
		stack->oper_set = ps_put_oper(stack, op1);
		return ;
	}
	ps_memset_oper(stack, 2);
}
