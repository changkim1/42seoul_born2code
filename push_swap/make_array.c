/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:01:53 by changkim          #+#    #+#             */
/*   Updated: 2022/07/20 18:14:47 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ps_check_array_size(char **av, int ac)
{
	int		i;
	int		j;
	int		idx;
	char	**split;

	i = 1;
	idx = 0;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		while (split[j])
		{
			if (ps_limit_check(split[j]) == 0)
			{
				exit (1);
			}
			idx++;
			j++;
		}
		i++;
	}
	return (idx);
}


int	*ps_make_array(char **av, int ac, int *array)
{
	
	int		i;
	int		j;
	int		idx;
	int		tmp;
	char	**split;

	i = 1;
	idx = 0;
	while (i < ac)
	{
		j = 0;
		split = ft_split(av[i], ' ');
		while (split[j])
		{
			array[idx] = ft_atoi(split[j]);
			idx++;
			j++;
		}
		i++;
	}
	return (array);
}