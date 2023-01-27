# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:36:19 by orakib            #+#    #+#              #
#    Updated: 2023/01/27 16:01:33 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

all : $(NAME)

$(NAME) : *.c push_swap.h
		cc -Wall -Werror -Wextra *.c -o $(NAME)

clean :
		rm -f push_swap
fclean : clean

re : fclean all

