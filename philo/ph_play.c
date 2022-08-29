/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:51:34 by changkim          #+#    #+#             */
/*   Updated: 2022/08/29 14:42:42 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_free_all(t_set *set)
{
	int	i;

	i = 0;
	while (i < set->philo_num)
	{
		pthread_mutex_destroy(&(set->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(set->print));
	free(set->philo);
	free(set->fork);
}

int	ph_play_run(t_set *set, t_philo *philo)
{
	pthread_mutex_lock(&(set->fork[philo->l_fork]));
	ph_print(set, philo->id, "has taken a fork");
	if (set->philo_num != 1)
	{
		pthread_mutex_lock(&(set->fork[philo->r_fork]));
		ph_print(set, philo->id, "has taken a fork");
		ph_print(set, philo->id, "is eating");
		philo->prev_eat_time = ph_get_time();
		philo->eat_count += 1;
		ph_time_warp(set, (long long)set->time_to_eat);
		pthread_mutex_unlock(&(set->fork[philo->r_fork]));
	}
	pthread_mutex_unlock(&(set->fork[philo->l_fork]));
	return (0);
}

void	*ph_play_ready(void *philo_idx)
{
	t_set	*set;
	t_philo	*philo;

	philo = (t_philo *)philo_idx;
	set = philo->set;
	if (philo->id % 2)
		usleep(1000);
	while (set->is_finish == 0)
	{
		ph_play_run(set, philo);
		if (philo->eat_count == set->must_eat_num)
		{
			set->eat_finish_count += 1;
			break ;
		}
		ph_print(set, philo->id, "is sleeping");
		ph_time_warp(set, (long long)set->time_to_sleep);
		ph_print(set, philo->id, "is thinking");
	}
	return (0);
}

int	ph_play_start(t_set *set)
{
	int	i;

	i = 0;
	while (i < set->philo_num)
	{
		set->philo[i].prev_eat_time = ph_get_time();
		if (pthread_create(&(set->philo[i].thr_id), NULL, ph_play_ready, &(set->philo[i])))
			return (-1);
		i++;
	}
	ph_finish_check(set);
	i = 0;
	while (i < set->philo_num)
	{
		pthread_join(set->philo[i].thr_id, NULL);
		i++;
	}
	ph_free_all(set);
	return (0);
}