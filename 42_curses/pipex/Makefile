# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 14:23:37 by zzankor           #+#    #+#              #
#    Updated: 2022/07/13 11:55:01 by changkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

CC			= cc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -rf

AR			= ar
ARFLAGS		= crs

INCLUDES	= ./pipex.h

SRCS		= pipex.c \
			  path.c \
			  utils.c \
			  error.c

OBJS		= $(SRCS:.c=.o)

OBJS_FILES = $(OBJS)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -c $<

$(NAME) : $(OBJS_FILES)
		$(MAKE) -C ./libft
		$(CC) $(CLFAG) $(OBJS_FILES) -L./libft -lft -o $(NAME)

clean :
		$(RM) $(OBJS)
		make clean -C libft

fclean : clean
		$(RM) $(NAME)
		$(RM) libft.a
		make fclean -C libft

re : fclean all

.PHONY : all clean fclean re bonus