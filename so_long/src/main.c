/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:40:46 by changkim          #+#    #+#             */
/*   Updated: 2022/06/27 22:27:40 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_game *game)
{
	free_map(game);
	mlx_destroy_window(game->ptr.mlx, game->ptr.win);
	exit(0);
}

void	check_ber_size(t_game *game)
{
	if (game->map.hei * SET_PIX >= MAX_HEI || game->map.wid * SET_PIX >= MAX_WID)
		print_error("Map is too big!\n", 0);
}

void	game_init(t_game *game, char *ber)
{
	game->ptr.mlx = mlx_init();
	if (game->ptr.mlx == 0)
		exit(1);
	check_map(game, ber);
	game->ptr.win = mlx_new_window(game->ptr.mlx,
			game->map.wid * 60, game->map.hei * 60, "changkim's so_long");
	if (game->ptr.win == 0)
		exit(1);
	img_set(game);
}

int	check_ber(char *av)
{
	int		i;
	int		ret;
	char	**str;

	i = 0;
	str = ft_split(av, '.');
	while (str[i])
		i++;
	i--;
	if (strcmp(str[i], "ber") == 0)
		ret = 1;
	else
		ret = 0;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (ret);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2 || check_ber(av[1]) == 0)
	{
		print_error("It must be './so_long [FILE.ber]'\n", (void *)1);
		return (0);
	}
	game_init(&game, av[1]);
	mlx_hook(game.ptr.win, X_EVENT_KEY_PRESS, 0, &press_key, &game);
	mlx_hook(game.ptr.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_loop(game.ptr.mlx);
}
