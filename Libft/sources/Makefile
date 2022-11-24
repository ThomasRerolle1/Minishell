# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/18 19:28:02 by mathis            #+#    #+#              #
#    Updated: 2021/12/14 14:12:45 by mravera          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#variables
CC = gcc
NAME = libft.a

SRC = ft_atoi.c \
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

SRC_BONUS = $(SRC) \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstadd_front.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#premiere commande qui va debuter toutes les autres
all : $(NAME)

#commande generique pour transformer tous les .c en .o
#%.o : %.c
#	$(CC) -o $@ -c $<

#commande de creation de la bibliotheque finale
$(NAME) : $(OBJ)
	ar rcs $@ $^

bonus : $(OBJ_BONUS)
	ar rcs $(NAME) $^

clean :
	$(RM) *.o

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
