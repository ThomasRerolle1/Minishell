# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 19:28:02 by mathis            #+#    #+#              #
#    Updated: 2022/10/08 02:40:24 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a

LIB_DIR = sources/
LIB_PRINTF = ./Printf_srcs/
LIB_GNL = ./gnl_srcs/

CFILES_LIB = ft_atoi.c \
	  ft_bzero.c \
	  ft_calloc.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c \
	  ft_putstr_fd.c \
	  ft_split.c \
	  ft_strchr.c \
	  ft_strdup.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_strmapi.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strtrim.c \
	  ft_substr.c \
	  ft_tolower.c \
	  ft_toupper.c

CFILES_BONUS = $(CFILES_LIB) \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRC_LIB = $(addprefix $(LIB_DIR), $(CFILES_LIB))
SRC_BONUS = $(addprefix $(LIB_DIR), $(CFILES_BONUS))

.o: %.c
	$(CC) -Wall -Wextra -Werror -c -g3 -fsanitise=address $< -o $@

OBJ_LIB = $(SRC_LIB:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

SRC_PRINTF = $(wildcard $(LIB_PRINTF)*.c)
OBJ_PRINTF = $(SRC_PRINTF:%.c=%.o)

SRC_GNL = $(wildcard $(LIB_GNL)*.c)
OBJ_GNL = $(SRC_GNL:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ_LIB) $(OBJ_PRINTF) $(OBJ_GNL)
	ar rcs $@ $^

bonus : $(OBJ_BONUS) $(OBJ_PRINTF) $(OBJ_GNL)
	ar rcs $(NAME) $^

clean :
	$(RM) *.o
	cd $(LIB_DIR) && $(RM) *.o
	cd $(LIB_PRINTF) && $(RM) *.o
	cd $(LIB_GNL) && $(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
