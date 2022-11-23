# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:19:45 by mravera           #+#    #+#              #
#    Updated: 2022/11/23 16:09:54 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= minishell

CC= gcc

CFLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address

RM= rm -rf

FOLDSRC= ./src/

SRC= ms_main.c

OBJS= $(FOLDSRC)$(SRC:.c=.o)

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	CC= clang
else
	NPROC := $(shell sysctl -n hw.ncpu)
endif

.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all 

.PHONY : all clean fclean re
