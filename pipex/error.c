/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:59:49 by changkim          #+#    #+#             */
/*   Updated: 2022/06/30 20:27:06 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error_with_nl(int exitcode, char *message)
{
	int		cmd_idx;
	char	*tmp;
	
	cmd_idx = px_strchr_idx(message, '-');
	if (cmd_idx != -1)
	{
		tmp = px_substr(message, 0, cmd_idx - 1);
		write(STDERR, tmp, px_strchr_idx(tmp, 0));
	}
	else
		write(STDERR, message, px_strchr_idx(message, 0));
	write(STDERR, "\n", 1);
	exit(exitcode);
}