/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:48:25 by changkim          #+#    #+#             */
/*   Updated: 2022/06/27 00:56:09 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_init(t_game *game)
{
	int		wid;
	int		hei;

	game->img.exit = mlx_xpm_file_to_image(game->ptr.mlx,
			"images/exit.xpm", &wid, &hei);
	game->img.minion = mlx_xpm_file_to_image(game->ptr.mlx,
			"images/minion.xpm", &wid, &hei);
	game->img.player = mlx_xpm_file_to_image(game->ptr.mlx,
			"images/player.xpm", &wid, &hei);
	game->img.teil = mlx_xpm_file_to_image(game->ptr.mlx,
			"images/teil.xpm", &wid, &hei);
	game->img.wall = mlx_xpm_file_to_image(game->ptr.mlx,
			"images/wall.xpm", &wid, &hei);
}

void	put_image(t_game *game, int h, int w)
{
	if (game->map.map[h][w] == '1')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win, game->img.wall,
			w * SET_PIX, h * SET_PIX);
	else if (game->map.map[h][w] == 'C')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win, game->img.minion,
			w * SET_PIX, h * SET_PIX);
	else if (game->map.map[h][w] == 'E')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win, game->img.exit,
			w * SET_PIX, h * SET_PIX);
	else if (game->map.map[h][w] == 'P')
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win, game->img.player,
			w * SET_PIX, h * SET_PIX);
	else
		mlx_put_image_to_window(game->ptr.mlx, game->ptr.win, game->img.teil,
			w * SET_PIX, h * SET_PIX);
}

void	img_set(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	img_init(game);
	while (i < game->map.hei)
	{
		j = 0;
		while (j < game->map.wid)
		{
			put_image(game, i, j);
			j++;
		}
		i++;
	}
}
