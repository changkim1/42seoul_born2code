/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:39:43 by changkim          #+#    #+#             */
/*   Updated: 2022/08/30 19:33:16 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_set_check(t_set *set)
{
	if (set->philo_num < 1 || set->time_to_die < 0
		|| set->time_to_eat < 0 || set-> time_to_sleep < 0)
		return (-1);
	return (0);
}

void	ph_finish_check(t_set *set, t_philo *philo)
{
	int			i;
	long long	now;

	while (1)
	{
		pthread_mutex_lock(&(set->multi_use));
		if (set->is_finish)
		{
			pthread_mutex_unlock(&(set->multi_use));
			break ;
		}
		if (set->must_eat_num != 0 && set->eat_finish_count == set->philo_num)
		{
			set->is_finish = 1;
			pthread_mutex_unlock(&(set->multi_use));
			break ;
		}
		pthread_mutex_unlock(&(set->multi_use));
		i = 0;
		while (i < set->philo_num)
		{
			now = ph_get_time();
			pthread_mutex_lock(&(set->multi_use));
			if ((now - philo[i].prev_eat_time) >= set->time_to_die)
			{
				ph_print(set, set->philo[i].id, "died");
				pthread_mutex_lock(&(set->multi_use));
				set->is_finish = 1;
				pthread_mutex_unlock(&(set->multi_use));
				break ;
			}
			pthread_mutex_unlock(&(set->multi_use));
			i++;
		}
	}
}
