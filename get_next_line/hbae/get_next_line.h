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
char		*ft_linemaker(char *word);
char		*ft_newline(char *word);

 #endif
