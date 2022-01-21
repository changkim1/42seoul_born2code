/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 02:53:45 by changkim          #+#    #+#             */
/*   Updated: 2022/01/21 02:53:46 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i] == (char)c)
	{
		return ((char *)&str[i]);
	}
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
		{
			return ((char *)&str[i]);
		}
	}
	return (0);
}
