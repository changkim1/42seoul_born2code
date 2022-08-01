# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 14:23:37 by zzankor           #+#    #+#              #
#    Updated: 2022/08/01 21:31:58 by changkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -rf

AR			= ar
ARFLAGS		= crs

INCLUDES	= ./push_swap.h

SRCS		= push_swap.c \
			  make_array.c \
			  sort_array.c \
			  error.c \
			  check_array.c \
			  utils.c \
			  make_stack.c \
			  sort.c \
			  oper_utils.c \
			  oper_s.c \
			  oper_p.c \
			  oper_r.c
			  
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