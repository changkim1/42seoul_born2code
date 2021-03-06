/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:47:11 by changkim          #+#    #+#             */
/*   Updated: 2022/03/06 22:03:53 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (1);
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *backup, char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = -1;
	if (!backup)
	{
		backup = (char *)malloc(sizeof(char) * 1);
		backup[0] = 0;
	}
	if (!backup || !str)
		return (NULL);
	tmp = (char *)malloc(1 * (ft_strlen(str) + ft_strlen(backup) + 1));
	while (backup[++i])
		tmp[i] = backup[i];
	j = -1;
	while (str[++j])
		tmp[i + j] = str[j];
	tmp[i + j] = 0;
	free(backup);
	return (tmp);
}
