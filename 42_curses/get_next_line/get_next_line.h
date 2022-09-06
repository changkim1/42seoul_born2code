/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:58:41 by changkim          #+#    #+#             */
/*   Updated: 2022/03/02 19:48:20 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100000

size_t		ft_strlen(char *str);
char		*ft_strchr(char *str, char i);
char		*ft_strjoin(char *s1, char*s2);
char		*get_next_line(int fd);
char		*ft_read(int fd, char *word);
char		*ft_return_oneline(char *word);
char		*ft_backup(char *word);

#endif
