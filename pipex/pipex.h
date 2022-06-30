/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:52:02 by changkim          #+#    #+#             */
/*   Updated: 2022/06/30 12:39:32 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define IN 0
# define OUT 1

//////////////////////pipex.c//////////////////////


//////////////////////utils.c//////////////////////
int	px_ft_strchr_i(char *str, char c);





#endif