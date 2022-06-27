/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:29:15 by changkim          #+#    #+#             */
/*   Updated: 2022/06/27 22:00:13 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_wid_hei(t_game *game, int fd)
{
	char	*line;

	line = get_next_line_no_new_line(fd);
	free(line);
	game->map.wid = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line_no_new_line(fd);
		free(line);
		game->map.hei++;
	}
	check_ber_size(game);
}

void	make_map(char *ber, t_game *game)
{
	int	fd;
	int	i;

	fd = open(ber, O_RDONLY);
	game->map.hei = 0;
	check_wid_hei(game, fd);
	close(fd);
	game->map.map = (char **)malloc(sizeof(char *) * (game->map.hei + 1));
	if (!game->map.map)
		exit(1);
	fd = open(ber, O_RDONLY);
	if (fd <= 0)
		print_error("File open is Failed\n", 0);
	i = 0;
	while (i < game->map.hei)
	{
		game->map.map[i] = (char *)malloc(game->map.wid + 1);
		if (!game->map.map[i])
			exit(1);
		game->map.map[i] = get_next_line_no_new_line(fd);
		system("leaks -list so_long");
		i++;
	}
	close(fd);
}

void	wall_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.hei)
	{
		j = 0;
		while (j < game->map.wid)
		{
			if (i == 0 || i == (game->map.hei - 1))
			{
				if (game->map.map[i][j] != '1')
					print_error("Map error (wall error)\n", game);
			}
			else if (j == 0 || j == game->map.wid - 1)
			{
				if (game->map.map[i][j] != '1')
					print_error("Map error (wall error)\n", game);
			}
			j++;
		}
		i++;
	}
}

void	param_rect_check(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.hei)
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == 'P')
				game->map.cnt_p++;
			else if (game->map.map[i][j] == 'E')
				game->map.cnt_e++;
			else if (game->map.map[i][j] == 'C')
				game->map.cnt_m++;
			else if (game->map.map[i][j] != '0' && game->map.map[i][j] != '1')
				print_error("Map error (param error)\n", game);
			j++;
		}
		if (j != game->map.wid)
			print_error("Map error (rectangular error)\n", game);
	}
	if (game->map.cnt_p != 1 || game->map.cnt_e != 1 || game->map.cnt_m < 1)
		print_error("Map error (param error)\n", game);
}

void	check_map(t_game *game, char *ber)
{
	game->map.cnt_p = 0;
	game->map.cnt_e = 0;
	game->map.cnt_m = 0;
	make_map(ber, game);
	wall_check(game);
	param_rect_check(game);
}
