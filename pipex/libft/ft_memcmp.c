/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:13 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 22:37:20 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	if (!count)
		return (0);
	i = 0;
	cp1 = (unsigned char *)buf1;
	cp2 = (unsigned char *)buf2;
	while (cp1[i] == cp2[i] && i < count - 1)
		i++;
	return (cp1[i] - cp2[i]);
}
