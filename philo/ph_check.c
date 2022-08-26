/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:39:43 by changkim          #+#    #+#             */
/*   Updated: 2022/08/26 00:11:24 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_set_check(t_set *set)
{
	if (set->philo_num < 2 || set->philo_num > 200 || set->time_to_die < 60
		|| set->time_to_eat < 60 || set-> time_to_sleep < 60)
		return (-1);
	return (0);
}

void	ph_finish_check(t_set *set)
{
	int			i;
	long long	now;

	while (set->is_finish == 0)
	{
		if (set->must_eat_num != 0 && set->eat_finish_count == set->must_eat_num)
		{
			set->is_finish = 1;
			break ;
		}
		i = 0;
		while (i < set->philo_num)
		{
			now = ph_get_time();
			if ((now - set->philo[i].prev_eat_time) >= set->time_to_die)
			{
				ph_print(set, set->philo[i].id, "died");
				set->is_finish = 1;
				break ;
			}
			i++;
		}
	}
}
