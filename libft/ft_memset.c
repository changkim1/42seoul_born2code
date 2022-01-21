/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:16 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 15:54:29 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int value, size_t count)
{
	unsigned char	*s_dest;
	size_t			i;

	i = 0;
	s_dest = dest;
	while (i < count)
	{
		s_dest[i] = (unsigned char)value;
		i++;
	}
	return (dest);
}
