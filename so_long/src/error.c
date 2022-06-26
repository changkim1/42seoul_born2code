/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:40:59 by changkim          #+#    #+#             */
/*   Updated: 2022/06/27 00:40:10 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(void *check)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)check;
	while (i < map->hei)
	{
		free(map->map[i]);
		i++;
	}
}

void	print_error(char *error, void *free_check)
{
	printf("Error\n%s\n", error);
	if (free_check == 0)
		exit(1);
	if (error[0] == 'M')
		free_map(free_check);
	exit(1);
}
