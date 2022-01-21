/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:33 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 02:53:34 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
