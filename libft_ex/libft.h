#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	ft_bzero(void *dest, size_t count);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int i);
int		ft_isprint(int c);

void	*ft_memchr(const void *buf, int c, size_t count);
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t num);
void	*ft_memset(void *dest, int value, size_t count);

char    *ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strrchr(const char *str, int c);

int		ft_tolower(int c);
int		ft_toupper(int c);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif