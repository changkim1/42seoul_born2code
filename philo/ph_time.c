/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:28:21 by changkim          #+#    #+#             */
/*   Updated: 2022/08/29 14:42:55 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ph_get_time(void)
{
	struct timeval	get_time;
	
	if (gettimeofday(&get_time, NULL) == -1)
		return (-1);
	return ((get_time.tv_sec * 1000) + (get_time.tv_usec / 1000));
}

void	ph_time_warp(t_set *set, long long warp_time)
{
	long long	start;
	long long	after_warp;

	start = ph_get_time();
	while ((set->is_finish) == 0)
	{
		after_warp = ph_get_time();
		if ((after_warp - start) >= warp_time)
			break ;
		usleep(10);
	}
}
