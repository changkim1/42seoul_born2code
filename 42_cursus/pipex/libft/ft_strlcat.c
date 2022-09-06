/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:37 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 02:53:38 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size < d_len + 1)
		return (size + s_len);
	else
	{
		while (src[i] != 0 && d_len + i + 1 < size)
		{
			dest[d_len + i] = src[i];
			i++;
		}
		dest[d_len + i] = 0;
		return (d_len + s_len);
	}
}
