/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:41:35 by changkim          #+#    #+#             */
/*   Updated: 2022/03/06 15:26:32 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *backup, char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!backup)
	{
		backup = (char *)malloc(1);
		backup[0] = 0;
	}
	if (!str)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(backup) + ft_strlen(str) + 1);
	if (!tmp)
		return (NULL);
	while (backup[i])
	{
		tmp[i] = backup[i];
		i++;
	}
	while (str[j])
	{
		tmp[i + j] = str[j];
		j++;
	}
	tmp[i + j] = 0;
	free(backup);
	return (tmp);
}