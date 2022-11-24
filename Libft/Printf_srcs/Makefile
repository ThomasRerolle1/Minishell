# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 19:28:02 by mathis            #+#    #+#              #
#    Updated: 2022/10/07 22:37:39 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
CC = gcc
NAME = libftprintf.a

SRC = printf_is_arg.c \
	  printf_is_c.c \
	  printf_is_s.c \
	  printf_is_p.c \
	  printf_is_d.c \
	  printf_is_i.c \
	  printf_is_u.c \
	  printf_is_x.c \
	  printf_is_majx.c \
	  printf_is_pcent.c \
	  printf_putnbr_base.c \
	  printf_putnbr_base_ui.c \
	  printf_putnbr_basev.c \
	  printf_strlen_unsigned.c \
	  ft_printf.c \
	  printf_calloc.c \


OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
