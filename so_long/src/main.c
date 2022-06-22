/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:40:46 by changkim          #+#    #+#             */
/*   Updated: 2022/06/23 02:15:01 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_ptr *ptr, char *ber)
{
	t_map *map;
	
	ptr->mlx = mlx_init();
	check_map(map, ber);
	printf("check\n");
	ptr->win = mlx_new_window(ptr->mlx, map->wid * 60, map->hei * 60, 
			"changkim's so_long");
	printf("check\n");
}

int main(int ac, char **av)
{
	t_ptr	ptr;
	
	if (ac != 2)
	{
		print_error("It must be './so_long [FILE.ber]'\n", (void *)1);
		return (0);
	}
	game_init(&ptr, av[1]);
	mlx_loop(ptr.mlx);
}