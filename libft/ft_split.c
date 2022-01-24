/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:21 by changkim          #+#    #+#             */
/*   Updated: 2022/01/24 21:32:17 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	index_cnt(char const *s, char c)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			cnt++;
		}
	}
	return (cnt);
}

char	**free_all(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	*strdup_len(const char *s, size_t len)
{
	size_t	i;
	char	*str;

	if (!s || len == 0)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	index;
	char	**str;

	i = 0;
	index = 0;
	str = (char **)malloc((index_cnt(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	while (i < ft_strlen(s))
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i + j] != c && s[i + j])
				j++;
			str[index++] = strdup_len(&s[i], j);
			if (!str)
				return (free_all(str));
		}
		i = i + j + 1;
	}
	str[index] = 0;
	return (str);
}
