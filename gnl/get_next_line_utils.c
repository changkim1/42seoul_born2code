/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:03:07 by changkim          #+#    #+#             */
/*   Updated: 2022/02/15 19:52:40 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*cp_str;
	size_t	s_len;
	size_t	i;

	i = 0;
	s_len = ft_strlen((char *)str);
	cp_str = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!cp_str)
		return (0);
	while (str[i])
	{
		cp_str[i] = str[i];
		i++;
	}
	cp_str[i] = 0;
	return (cp_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	free(s1);
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	return (str);
}
