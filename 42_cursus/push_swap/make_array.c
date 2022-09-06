/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:01:53 by changkim          #+#    #+#             */
/*   Updated: 2022/08/05 00:21:11 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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
			if (ps_check_limit(split[j]) == 0)
				ps_print_error("arg is out of range");
			free(split[j]);
			idx++;
			j++;
		}
		free(split);
		i++;
	}
	return (idx);
}

int	*ps_make_array(char **av, int ac, int *array, int array_size)
{
	int			i;
	int			j;
	int			idx;
	char		**split;

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
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
	ps_check_duplicate(array, array_size);
	return (array);
}
