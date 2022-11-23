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

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
FOLDSRC = ./src/

NAME = minishell

SRC = ms_main.c

all = $(NAME)

$(NAME) : $(FOLDSRC)$(SRC:%.c=%.o)
	$(CC) $(CFLAGS) $^ -o $@

%.o : $(FOLDSRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(FOLDSRC)$(SRC:%.c=%.o)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

