/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:40:46 by changkim          #+#    #+#             */
/*   Updated: 2022/06/22 21:21:00 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

typedef struct mlx {
	void *mlx;
	void *win;
}	mlx;

int		close(int keycode, mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	return (0);
}

int main(void)
{
	mlx		mlx;
	void	*minion;
	void	*wall;
	void	*exit;
	void	*teil;
	void	*player;
	int		img_wid;
	int		img_hei;
	
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 900, 900, "test");
	minion = mlx_xpm_file_to_image(mlx.mlx, "../images/minion.xpm", &img_wid, &img_hei);
	exit = mlx_xpm_file_to_image(mlx.mlx, "../images/exit.xpm", &img_wid, &img_hei);
	player = mlx_xpm_file_to_image(mlx.mlx, "../images/player.xpm", &img_wid, &img_hei);
	teil = mlx_xpm_file_to_image(mlx.mlx, "../images/teil.xpm", &img_wid, &img_hei);
	wall = mlx_xpm_file_to_image(mlx.mlx, "../images/wall.xpm", &img_wid, &img_hei);
	mlx_put_image_to_window(mlx.mlx, mlx.win, minion, 0, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, exit, 64, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, player, 200, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, teil, 100, 0);
	mlx_put_image_to_window(mlx.mlx, mlx.win, wall, 500, 0);
	mlx_loop(mlx.mlx);
	mlx_hook(mlx.win, close, &mlx);
	mlx_loop(mlx.mlx);

}