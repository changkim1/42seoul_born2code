# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzankor <zzankor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 14:23:37 by zzankor           #+#    #+#              #
#    Updated: 2022/05/21 14:26:00 by zzankor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -rf

AR			= ar
ARFLAGS		= crs

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
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		$(AR) $(ARFLAGS) $(NAME) $(OBJS_FILES)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus