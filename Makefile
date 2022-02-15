# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 18:44:44 by anifanto          #+#    #+#              #
#    Updated: 2021/11/23 17:36:57 by anifanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

LIST = 	push_swap.c			ft_sorts.c			ft_utils.c\
		ft_check_input.c	ft_to_print.c		ft_split_nbr.c\
		ft_error_free.c		ft_atoi.c			ft_add_to_stack.c\
		ft_libf.c			ft_operations.c		ft_operations2.c\
		ft_operations3.c	ft_init.c

CFLAGS = -Wall -Wextra -Werror

LIST_P = $(addprefix src/, $(LIST))

HEADER = inc/push_swap.h

compile :
	gcc $(CFLAGS) $(LIST_P) $< -o $(NAME)

all:	compile

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY : all clean fclean re