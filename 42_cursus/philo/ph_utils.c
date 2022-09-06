/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:26:53 by changkim          #+#    #+#             */
/*   Updated: 2022/08/30 18:46:32 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_print(t_set *set, int id, char *message)
{
	long long	now;

	now = ph_get_time();
	if (now == -1)
		return (-1);
	pthread_mutex_lock(&(set->print));
	if (set->is_finish == 0)
		printf("%lld %d %s\n", now - set->start_time, id + 1, message);
	pthread_mutex_unlock(&(set->print));
	return (0);
}

int	ph_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ph_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ph_atoi(char *str)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (ph_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (ph_error("ERROR : ARG IS MINUS"));
		i++;
	}
	while (str[i])
	{
		if (!ph_isdigit(str[i]))
			return (ph_error("ERROR : ARR IS NOT NUM"));
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

int	ph_error(char *message)
{
	printf("%s\n", message);
	return (-1);
}