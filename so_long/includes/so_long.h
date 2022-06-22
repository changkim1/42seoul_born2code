/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:19:48 by changkim          #+#    #+#             */
/*   Updated: 2022/06/23 01:39:11 by changkim         ###   ########.fr       */
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
# include "../get_next_line/get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

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

typedef struct s_game{
	int		collect;
	int		walk;
}				t_game;

typedef struct s_ptr{
	void	*mlx;
	void	*win;
}				t_ptr;

typedef struct s_player_coo{
	int	x;
	int	y;
}				t_player_coo;

/////////////////// main.c ///////////////////
void	game_init(t_ptr *ptr, char *ber);


/////////////////// error.c ///////////////////
void	print_error(char *error, void *check);


/////////////////// map.c ///////////////////
void	check_wid_hei(t_map *map, int fd);
void	make_map(char *ber, t_map *map);
void	wall_check(t_map *map);
void	param_rect_check(t_map *map);
void	check_map(t_map *map, char *ber);


#endif
