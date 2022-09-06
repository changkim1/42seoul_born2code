/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:52:55 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 15:54:48 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t count)
{
	unsigned char	*s_dest;
	size_t			i;

	i = 0;
	s_dest = (unsigned char *)dest;
	while (i < count)
	{
		s_dest[i] = 0;
		i++;
	}
}
