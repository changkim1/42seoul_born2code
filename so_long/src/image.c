/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:48:25 by changkim          #+#    #+#             */
/*   Updated: 2022/06/26 21:26:23 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_img	img_init(t_ptr *ptr)
{
	t_img	img;
	int		wid;
	int		hei;
	
	img.exit = mlx_xpm_file_to_image(ptr->mlx, "images/exit.xpm", &wid, &hei);
	img.minion = mlx_xpm_file_to_image(ptr->mlx, "images/minion.xpm", &wid, &hei);
	img.player = mlx_xpm_file_to_image(ptr->mlx, "images/player.xpm", &wid, &hei);
	img.teil = mlx_xpm_file_to_image(ptr->mlx, "images/teil.xpm", &wid, &hei);
	img.wall = mlx_xpm_file_to_image(ptr->mlx, "images/wall.xpm", &wid, &hei);
	return (img);
}

void	put_image(t_img *img, t_map *map, t_ptr *ptr, int h, int w)
{
	if (map->map[h][w] == '1')
		mlx_put_image_to_window(ptr->mlx, ptr->win, img->wall, w * SET_PIX, h * SET_PIX);
	else if (map->map[h][w] == 'C')
		mlx_put_image_to_window(ptr->mlx, ptr->win, img->minion, w * SET_PIX, h * SET_PIX);
	else if (map->map[h][w] == 'E')
		mlx_put_image_to_window(ptr->mlx, ptr->win, img->exit, w * SET_PIX, h * SET_PIX);
	else if (map->map[h][w] == 'P')
		mlx_put_image_to_window(ptr->mlx, ptr->win, img->player, w * SET_PIX, h * SET_PIX);
	else
		mlx_put_image_to_window(ptr->mlx, ptr->win, img->teil, w * SET_PIX, h * SET_PIX);
}

void	img_set(t_map *map, t_ptr *ptr)
{
	int		i;
	int		j;
	t_img	img;

	i = 0;
	img = img_init(ptr);
	while (i < map->hei)
	{
		j = 0;
		while (j < map->wid)
		{
			put_image(&img, map, ptr, i, j);
			j++;
		}
		i++;
	}
}