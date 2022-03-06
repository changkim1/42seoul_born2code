/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:40:13 by changkim          #+#    #+#             */
/*   Updated: 2022/03/06 15:10:45 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 3
# define OPEN_MAX 256

# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *backup, char *str);
char	*ft_read(char *backup, int fd);
char	*ft_return_oneline(char *backup);
char	*ft_backup(char *backup);
char	*get_next_line(int fd);

#endif
