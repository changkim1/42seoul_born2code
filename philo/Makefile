# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: changkim <changkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/29 14:01:46 by changkim          #+#    #+#              #
#    Updated: 2022/08/30 18:04:06 by changkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= cc
CFLAG		= -Wall -Wextra -Werror

SANFLAG		= -fsanitize=thread -g

RM			= rm -rf

AR			= ar
ARFLAGS		= crs

INCLUDES	= ./philo.h

SRCS		= main.c \
			  ph_check.c \
			  ph_play.c \
			  ph_setting.c \
			  ph_time.c \
			  ph_utils.c \
			  
OBJS		= $(SRCS:.c=.o)

OBJS_FILES = $(OBJS)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAG) $(SANFLAG) -c $<

$(NAME) : $(OBJS_FILES)
		$(CC) $(CLFAG) $(SANFLAG) $(OBJS_FILES) -o $(NAME) -lpthread

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus