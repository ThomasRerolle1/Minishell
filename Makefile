# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:19:45 by mravera           #+#    #+#              #
#    Updated: 2022/11/24 15:03:36 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIBS = -L Libft -lft

RM = rm -rf

FOLDSRC = ./src/

SRC = ms_main.c

OBJS = $(FOLDSRC)$(SRC:.c=.o)

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	CC = clang
else
	NPROC := $(shell sysctl -n hw.ncpu)
endif

.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(MAKE) -C Libft
	$(CC) $(OBJS) $(CFLAGS) $(LIBS) -o $(NAME)

all : $(NAME)

clean :
	$(MAKE) clean -C Libft
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C Libft
	$(RM) $(NAME)

re : fclean all 

.PHONY : all clean fclean re
