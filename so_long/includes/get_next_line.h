/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:41:40 by changkim          #+#    #+#             */
/*   Updated: 2022/06/23 00:10:29 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define OPEN_MAX 256
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

int		ft_strchr_gnl(char *str, char c);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *backup, char *str);
char	*ft_backup(char *backup);
char	*ft_return_oneline(char *backup);
char	*ft_read(char *backup, int fd);
char	*get_next_line_no_new_line(int fd);

#endif
