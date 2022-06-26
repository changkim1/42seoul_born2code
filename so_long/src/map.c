/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:29:15 by changkim          #+#    #+#             */
/*   Updated: 2022/06/26 21:59:40 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_wid_hei(t_map *map, int fd)
{
	char	*line;
	
	line = get_next_line_no_new_line(fd);
	map->wid = ft_strlen(line);
	while (line != NULL)
	{
		line = get_next_line_no_new_line(fd);
		map->hei++;
	}
}

void	make_map(char *ber, t_map *map)
{
	int	fd;
	int	i;
	
	fd = open(ber, O_RDONLY);
	map->hei = 0;
	check_wid_hei(map, fd);
	close(fd);
	map->map = (char **)malloc(sizeof(char *) * (map->hei + 1));
	if (!map->map)
		exit(1);
	fd = open(ber, O_RDONLY);
	if (fd <= 0)
		print_error("File open is Failed\n", 0);
	i = 0;
	while (i < map->hei)
	{
		map->map[i] = (char *)malloc(map->wid + 1);
		if (!map->map[i])
			exit(1);
		map->map[i] = get_next_line_no_new_line(fd);
		i++;
	}
	close(fd);
}

void	wall_check(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->hei)
	{
		j = 0;
		while (j < map->wid)
		{
			if (i == 0 || i == (map->hei - 1))
			{
				if (map->map[i][j] != '1')
					print_error("Map error (wall error)\n", (void *)map);
			}
			else if (j == 0 || j == map->wid - 1)
			{
				if (map->map[i][j] != '1')
					print_error("Map error (wall error)\n", (void *)map);
			}
			j++;
		}
		i++;
	}
}

void	param_rect_check(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->hei)
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'P')
				map->cnt_p++;
			else if (map->map[i][j] == 'E')
				map->cnt_e++;
			else if (map->map[i][j] == 'C')
				map->cnt_m++;
			j++;
		}
		if (j != map->wid)
			print_error("Map error (rectangular error)\n", (void *)map);
	}
	if (map->cnt_p != 1 || map->cnt_e != 1 || map->cnt_m < 1)
		print_error("Map error (param error)\n", (void *)map);
}

void	check_map(t_map *map, char *ber)
{
	map->cnt_p = 0;
	map->cnt_e = 0;
	map->cnt_m = 0;
	make_map(ber, map);
	wall_check(map);
	param_rect_check(map);
}