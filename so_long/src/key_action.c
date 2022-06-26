/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:46:38 by changkim          #+#    #+#             */
/*   Updated: 2022/06/26 23:03:38 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	where_is_player_at_first(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.hei)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
			{
				game->p_coo.x = j;
				game->p_coo.y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	success_mission(t_game *game)
{
	game->walk++;
	printf("%d\n", game->walk);
	printf("Teemo is Godlike!\n");
	exit(0);
}

int	check_move(t_game *game, int i, int j)
{
	int	can_move;

	can_move = 0;
	if (game->map.map[i][j] == '1')
		printf("If GBM crossed the wall...\n");
	else if (game->map.map[i][j] == 'E')
	{
		if (game->collect == game->map.cnt_m)
			success_mission(game);
		else
			printf("You must take %d minion(s) more\n", 
				game->map.cnt_m - game->collect);
	}
	else
	{
		game->walk++;
		printf("%d\n", game->walk);
		game->p_coo.y = i;
		game->p_coo.x = j;
		if (game->map.map[i][j] == 'C')
			game->collect++;
		can_move = 1;
	}
	return (can_move);
}

void	moving(t_game *game, int keycode)
{
	int	i;
	int	j;
	int	can_move;
	
	where_is_player_at_first(game);
	can_move = 0;
	i = game->p_coo.y;
	j = game->p_coo.x;
	if (keycode == KEY_A)
		can_move = check_move(game, i, j - 1);
	else if (keycode == KEY_W)
		can_move = check_move(game, i - 1, j);
	else if (keycode == KEY_S)
		can_move = check_move(game, i + 1, j);
	else if (keycode == KEY_D)
		can_move = check_move(game, i, j + 1);
	if (can_move == 1)
	{
		game->map.map[i][j] = '0';
		i = game->p_coo.y;
		j = game->p_coo.x;
		game->map.map[i][j] = 'P';
		img_set(&game->map, &game->ptr);
	}
}

int		press_key(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else
		moving(game, keycode);
	return (0);
}
