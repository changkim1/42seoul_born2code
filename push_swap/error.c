/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:05:55 by zzankor           #+#    #+#             */
/*   Updated: 2022/07/15 15:38:36 by zzankor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ps_check_duplicate(int *array, int w_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < w_count)
	{
		j = i + 1;
		while (j < w_count)
		{
			if (array[j] == array[i])
			{
				free(array);
				ps_print_error("arg is duplicate");
			}
			j++;
		}
		i++;
	}
}

void	ps_print_error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	exit(1);
}