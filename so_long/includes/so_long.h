/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:48 by changkim          #+#    #+#             */
/*   Updated: 2022/06/27 00:58:07 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx_lib/mlx.h"
# include "../libft/libft.h"
# include "../includes/get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define SET_PIX 60
# define MAX_HEI 1440
# define MAX_WID 2560

typedef struct s_img{
	void	*player;
	void	*wall;
	void	*minion;
	void	*teil;
	void	*exit;
}				t_img;

typedef struct s_map{
	int		wid;
	int		hei;
	int		cnt_p;
	int		cnt_e;
	int		cnt_m;
	char	**map;
}				t_map;

typedef struct s_ptr{
	void	*mlx;
	void	*win;
}				t_ptr;

typedef struct s_p_coo{
	int	x;
	int	y;
}				t_p_coo;

typedef struct s_game{
	t_ptr	ptr;
	t_map	map;
	t_img	img;
	t_p_coo	p_coo;
	int		collect;
	int		walk;
}				t_game;

/////////////////// main.c ///////////////////
void	game_init(t_game *game, char *ber);
int		exit_game(t_game *game);
void	check_ber_size(t_map *map);

/////////////////// error.c ///////////////////
void	print_error(char *error, void *free_check);
void	free_map(void *check);

/////////////////// map.c ///////////////////
void	check_wid_hei(t_map *map, int fd);
void	make_map(char *ber, t_map *map);
void	wall_check(t_map *map);
void	param_rect_check(t_map *map);
void	check_map(t_map *map, char *ber);

/////////////////// image.c ///////////////////
void	img_init(t_game *game);
void	put_image(t_game *game, int h, int w);
void	img_set(t_game *game);

/////////////////// key_action.c ///////////////////
void	where_is_player_at_first(t_game *game);
void	success_mission(t_game *game);
int		check_move(t_game *game, int i, int j);
int		press_key(int keycode, t_game *game);
void	moving(t_game *game, int keycode);

#endif
