/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:28:32 by changkim          #+#    #+#             */
/*   Updated: 2022/08/29 14:19:09 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
	t_set	set;

	if (ac != 5 && ac != 6)
		return (ph_error("ERROR : ARG NUM ERROR"));
	if (ph_set_init(&set, ac, av))
		return (ph_error("ERROR : SET INIT ERROR"));
	if (ph_play_start(&set))
		return (ph_error("ERROR : PLAY START ERROR"));
	return (0);
}