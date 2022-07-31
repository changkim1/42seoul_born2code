/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 16:23:45 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/15 16:27:16 by zzankor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ps_arg_valid_check(long long tmp)
{
	if (tmp > 2147483647)
		return (1);
	else if (tmp < -2147483648)
		return (1);
	else
		return (0);
}

int	ps_count_word(int ac, char **av)
{
	int			i;
	int			j;
	char		**str;
	long long	tmp;
	int			w_count;

	i = 1;
	w_count = 0;
	while (i < ac)
	{
		str = ft_split(av[i], ' ');
		j = 0;
		while (str[j])
		{
			w_count++;
			j++;
		}
		free(str);
		i++;
	}
	return (w_count);
}

int	*ps_make_array(int ac, char **av, int w_count, int *array)
{
	int			i;
	int			j;
	char		**str;
	long long	tmp;
	int			array_i;

	i = 0;
	array_i = -1;
	array = (int *)malloc(sizeof(int) * w_count);
	while (++i < ac)
	{
		str = ft_split(av[i], ' ');
		j = -1;
		while (str[++j])
		{
			tmp = ps_atoi_ll(str[j]);
			if (ps_arg_valid_check(tmp))
			{
				ps_print_error("arg over int range");
				ps_free_str(str);
			}
			array[++array_i] = tmp;
		}
	}
	return (array);
}
