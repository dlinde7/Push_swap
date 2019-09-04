# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlinde <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 13:29:33 by dlinde            #+#    #+#              #
#    Updated: 2019/09/04 16:10:57 by dlinde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

FILES = subfun/push.a \
		subfun/libft/libft.a

CC	=	gcc

FLAGS = -Wall -Wextra -Werror

all: pre $(NAME1) $(NAME2)

pre:
	@cd subfun && make
	@cd subfun && make clean
	@cd subfun/libft && make
	@cd subfun/libft && make clean

$(NAME1):
	@$(CC) $(FLAGS) $(FILES) checker.c -o $(NAME1)

$(NAME2):
	@$(CC) $(FLAGS) $(FILES) push_swap.c -o $(NAME2)

clean:
	@cd subfun && make fclean
	@cd subfun/libft && make fclean

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)

re: fclean all
