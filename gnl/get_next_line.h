/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:10:28 by changkim          #+#    #+#             */
/*   Updated: 2022/02/15 19:52:17 by changkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h> //open(), O_RDONLY

# ifndef OPEN_MAX
#  define OPEN_MAX 65536
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif