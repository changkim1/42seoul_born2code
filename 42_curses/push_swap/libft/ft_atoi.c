/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:52:52 by changkim          #+#    #+#             */
/*   Updated: 2022/07/31 15:24:00 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pass_blank(const char *str)
{
	int	i;

	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	return (i);
}

int	over_under_int(long long num, int plma)
{
	if (num * plma > 2147483647)
		return (-1);
	else if (num * plma < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			plma;

	i = pass_blank(str);
	num = 0;
	plma = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			plma *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (num * plma > 2147483647 || num * plma < -2147483648)
			return (over_under_int(num, plma));
		num += (str[i] - '0');
		if (str[++i] >= '0' && str[i] <= '9')
			num *= 10;
	}
	return ((int)num * plma);
}
