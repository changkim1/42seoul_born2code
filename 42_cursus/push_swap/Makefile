# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changkim <changkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 14:23:37 by zzankor           #+#    #+#              #
#    Updated: 2022/08/04 23:10:25 by changkim         ###   ########.fr        #
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
			  make_stack.c \
			  sort.c \
			  sort_over_3.c \
			  sort_utils.c \
			  sort_move.c \
			  oper_s.c \
			  oper_p.c \
			  oper_r.c \
			  oper_rr.c \
			  real_loc.c \
			  real_loc_utils.c \
			  get_min_max.c
			  
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