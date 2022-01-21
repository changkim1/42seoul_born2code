/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:46 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 02:53:47 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	l;
	size_t	r;
	char	*str;

	l = 0;
	if (!s1)
		return (0);
	r = ft_strlen((char *)s1);
	while (s1[l] && ft_strchr(set, s1[l]))
		l++;
	while (r && ft_strrchr(set, s1[r]))
		r--;
	if (l >= r)
		return ((char *)ft_calloc(sizeof(char), 1));
	str = ft_substr(s1, l, r - l + 1);
	return (str);
}
