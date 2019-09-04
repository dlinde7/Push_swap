# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlinde <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 13:05:38 by dlinde            #+#    #+#              #
#    Updated: 2019/09/04 13:09:16 by dlinde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push.a

FILES = addon.c \
		error.c \
		five.c \
		ops.c \
		sortab.c \
		checkab.c \
		finalsort.c

CC	=	gcc

FLAGS = -Wall -Wextra -Werror

LIB = push.h

OBJ = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(FILES) -I $(LIB)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
