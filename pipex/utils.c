/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 12:36:47 by changkim          #+#    #+#             */
/*   Updated: 2022/07/09 17:17:54 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

int	px_strchr_idx(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	if (c == 0)
		return (i);
	return (-1);
}

char	*px_strdup(char *src)
{
	int		i;
	char	*dst;

	i = 0;
	while (src[i])
		i++;
	dst = (char *)malloc(i);
	if (!dst)
		return ((void *)0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

int	px_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	*px_substr(char *src, int head, int len)
{
	char	*str;
	int		i;
	int		j;

	if (!src)
		return ((void *)0);
	str = (char *)malloc(len + 1);
	if (!str)
		return ((void *)0);
	i = head;
	j = 0;
	while (j < len)
	{
		str[j] = src[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

char	*px_strjoin(char *dst, char *src)
{
	int		i;
	int		j;
	char	*ret;

	if (!dst)
		return (src);
	i = px_strchr_idx(dst, 0);
	j = px_strchr_idx(src, 0);
	ret = (char *)malloc(i + j + 1);
	if (!ret)
		return (0);
	i = -1;
	j = 0;
	while (dst[++i])
		ret[i] = dst[i];
	while (src[j])
	{
		ret[i + j] = src[j];
		j++;
	}
	ret[i + j] = 0;
	free(dst);
	return (ret);
}
