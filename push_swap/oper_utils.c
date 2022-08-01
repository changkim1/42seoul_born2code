/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:20:45 by changkim          #+#    #+#             */
/*   Updated: 2022/08/01 19:14:20 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ps_put_oper(char **oper_set, char *oper)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlen(oper);
	if (oper_set[0] != NULL)
		i++;
	oper_set[i] = (char *)malloc(len + 1);
	while (oper[j])
	{
		oper_set[i][j] = oper[j];
		j++;
	}
	oper_set[i][j] = 0;
	return (oper_set);
}

void	ps_memset_oper(char **oper_set, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_memset(oper_set[i], 0, ft_strlen(oper_set[i]));
		i++;
	}
}

void	ps_check_double(char **oper_set, char *op1, char *op2, char *op_double)
{
	if (oper_set[0] == NULL || oper_set[1] == NULL)
		return ;
	if (ft_strcmp(oper_set[0], op1) == 0)
	{
		if (ft_strcmp(oper_set[1], op2) == 0)
			write(1, op_double, ft_strlen(op_double));
	}
	else if (ft_strcmp(oper_set[0], op2) == 0)
	{
		if (ft_strcmp(oper_set[1], op1) == 0)
			write(1, op_double, ft_strlen(op_double));
	}
	else
	{
		write(1, op1, ft_strlen(op1));
		ps_memset_oper(oper_set, 1);
		oper_set = ps_put_oper(oper_set, op2);
		return ;
	}
	ps_memset_oper(oper_set, 2);
}
