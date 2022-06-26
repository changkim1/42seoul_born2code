/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:40:59 by changkim          #+#    #+#             */
/*   Updated: 2022/06/26 20:37:04 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(void *check)
{
	t_map	*map;
	int 	i;

	i = 0;
	map = (t_map *)check;
	while (i < map->hei)
	{
		free(map->map[i]);
		i++;
	}
}

void	print_error(char *error, void *check)
{
	write(2, "Error\n", 6);
	write(1, error, ft_strlen(error));
	if (check == 0)
		exit(1);
	if (error[0] == 'M')
		free_map(check);
	exit(1);
}
