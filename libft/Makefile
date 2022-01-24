NAME		= libft.a

CC			= gcc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -rf

AR			= ar
ARFLAGS		= curs

INCLUDES	= ./libft.h

SRCS		= ft_atoi.c \
			  ft_bzero.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_strchr.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strnstr.c \
			  ft_strncmp.c \
			  ft_strrchr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c 

SRCS_B		= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c \


OBJS		= $(SRCS:.c=.o)

OBJS_B		= $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	OBJS_FILES = $(OBJS_B)

else
	OBJS_FILES = $(OBJS)

endif

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -c $<

$(NAME) : $(OBJS_FILES)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_FILES)

bonus : 
		make WITH_BONUS=1 all

clean :
		$(RM) $(OBJS) $(OBJS_B)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus