/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 00:40:59 by changkim          #+#    #+#             */
/*   Updated: 2022/06/27 22:22:37 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.hei)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

void	print_error(char *error, t_game *game)
{
	printf("Error\n%s\n", error);
	if (game == 0)
		exit(1);
	if (error[0] == 'M')
		free_map(game);
	exit(1);
}
