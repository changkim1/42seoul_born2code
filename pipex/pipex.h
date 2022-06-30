/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:52:02 by changkim          #+#    #+#             */
/*   Updated: 2022/06/30 20:30:34 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <sys/stat.h>
# include "libft/libft.h"


#include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define IN 0
# define OUT 1

//////////////////////pipex.c//////////////////////
int		px_open_file(char *filename, int check);
void	px_redirection(char *cmd, char **envp);
void	px_execve(char *cmd, char **envp);


//////////////////////path.c//////////////////////
char	*px_change_to_slash(char *path);
char	*px_make_path(char **envp, char **cmd);
char	*px_find_path(char **envp);


//////////////////////utils.c//////////////////////
int		px_strchr_idx(char *str, char c);
char	*px_strdup(char *src);
int		px_strncmp(char *s1, char *s2, int n);
char	*px_substr(char *src, int head, int len);
char	*px_strjoin(char *dst, char *src);

//////////////////////error.c//////////////////////
void	print_error_with_nl(int exitcode, char *message);



#endif