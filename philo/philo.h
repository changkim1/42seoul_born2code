/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:12:13 by changkim          #+#    #+#             */
/*   Updated: 2022/08/30 19:32:43 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				eat_count;
	long long		prev_eat_time;
	struct s_set	*set;
	pthread_t		thr_id;
}				t_philo;

typedef struct s_set
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	int				is_finish;
	int				eat_finish_count;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	multi_use;
	t_philo			*philo;
}				t_set;


////////////////ph_utils.c////////////////
int	ph_isspace(char c);
int	ph_atoi(char *str);
int	ph_error(char *message);
int	ph_print(t_set *set, int id, char *message);

////////////////ph_check.c////////////////
int	ph_set_check(t_set *set);
void	ph_finish_check(t_set *set, t_philo *philo);

////////////////ph_setting.c////////////////
int	ph_philo_init(t_set *set, t_philo **philo);
int	ph_mut_init(t_set *set);
int	ph_set_init(t_set *set, int ac, char **av);

////////////////ph_time.c////////////////
long long	ph_get_time(void);
void	ph_time_warp(long long warp_time);

////////////////ph_play.c////////////////
int	ph_play_start(t_set *set, t_philo *philo);
void	*ph_play_ready(void *philo_idx);
int	ph_play_run(t_set *set, t_philo *philo);
void	ph_free_all(t_set *set, t_philo *philo);


#endif