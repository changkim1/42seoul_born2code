NAME		= ft_printf.a

CC			= gcc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -rf

AR			= ar
ARFLAGS		= curs

INCLUDES	= ./ft_printf.h

SRCS		= ft_printf.c \
			  char_print.c \
			  hex_print.c \
			  number_print.c \
			  pointer_print.c


OBJS		= $(SRCS:.c=.o)

OBJS_FILES = $(OBJS)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -c $<

$(NAME) : $(OBJS_FILES)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_FILES)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus