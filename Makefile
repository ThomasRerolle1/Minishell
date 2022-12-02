# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 17:19:45 by mravera           #+#    #+#              #
#    Updated: 2022/12/02 18:31:55 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LIBS = -L Libft -lft -ledit
RM = rm -rf
FOLDSRC = ./src/
SRC = ms_main.c \
			ms_supersplit.c \
			ms_utils.c

OBJS = $(addprefix $(FOLDSRC), $(SRC:.c=.o))

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	CC = clang
else
	NPROC := $(shell sysctl -n hw.ncpu)
endif

$(NAME) : $(OBJS)
	$(MAKE) -C Libft
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME)

ffclean : clean
	$(MAKE) fclean -C Libft
	$(RM) $(NAME)

re : fclean all 

fre :ffclean all

.PHONY : all clean fclean ffclean re fre
