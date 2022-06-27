# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changkim <changkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 19:40:59 by changkim          #+#    #+#              #
#    Updated: 2022/06/27 21:22:22 by changkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

MLX			= -L./mlx_lib -lmlx -framework OpenGL -framework AppKit

CC			= gcc
CFLAG		= -Wall -Wextra -Werror

RM			= rm -rf

AR			= ar
ARFLAGS		= crs

INCLUDES	= includes/so_long.h \
			  includes/get_next_line.h

SRCS		= src/main.c \
			  src/error.c \
			  src/map.c \
			  src/image.c \
			  src/key_action.c \
			  src/get_next_line.c \
			  src/get_next_line_utils.c


OBJS		= $(SRCS:.c=.o)

OBJS_FILES = $(OBJS)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) -c $< -o $@
		

$(NAME) : $(OBJS_FILES)
		
		$(MAKE) -C ./libft
		$(CC) $(CFLAG) $(OBJS_FILES) -L./libft -lft $(MLX) -g -o $(NAME)

clean :
		$(RM) $(OBJS)
		make clean -C libft/

fclean : clean
		$(RM) $(NAME) $(OBJS_FILES)
		$(RM) libft.a
		make fclean -C libft/

git : fclean
		cd includes; rm -rf *.gch
		rm -rf *.ber
		git add *
		git commit -m "so_long"
		git push

re : fclean all

.PHONY : all clean fclean re bonus