/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_setting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:35:05 by changkim          #+#    #+#             */
/*   Updated: 2022/08/26 00:18:53 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_philo_init(t_set *set)
{
	int	i;

	i = 0;
	set->philo = malloc(sizeof(t_philo) * set->philo_num);
	if (!(set->philo))
		return (-1);
	while (i < set->philo_num)
	{
		set->philo[i].id = i;
		set->philo[i].l_fork = i;
		set->philo[i].r_fork = (i + 1) % set->philo_num;
		set->philo[i].eat_count = 0;
		set->philo[i].set = set;
		set->philo[i].prev_eat_time = 0;
		i++;
	}
	return (0);
}

int	ph_mut_init(t_set *set)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&(set->print), NULL))
		return (-1);
	set->fork = malloc(sizeof(pthread_mutex_t) * set->philo_num);
	if (!(set->fork))
		return (-1);
	while (i < set->philo_num)
	{
		if (pthread_mutex_init(&(set->fork[i]), NULL))
			return (-1);
		i++;
	}
	return (0);
}

int	ph_set_init(t_set *set, int ac, char **av)
{
	set->philo_num = ph_atoi(av[1]);
	set->time_to_die = ph_atoi(av[2]);
	set->time_to_eat = ph_atoi(av[3]);
	set->time_to_sleep = ph_atoi(av[4]);
	set->is_finish = 0;
	set->eat_finish_count = 0;
	set->start_time = ph_get_time();
	if (ph_set_check(set) != 0)
		return (ph_error("ERROR : ARG SET ERROR"));
	if (ac == 6)
	{
		set->must_eat_num = ph_atoi(av[5]);
		if (set->must_eat_num <= 0)
			return (ph_error("ERROR : MUST EAT SET ERROR"));
	}
	if (ph_mut_init(set))
		return (-1);
	if (ph_philo_init(set))
		return (-1);
	return (0);
}