# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orakib <orakib@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 17:36:19 by orakib            #+#    #+#              #
#    Updated: 2023/02/01 14:55:43 by orakib           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRC = algo.c algo2.c algo3.c algo4.c \
		algo5.c algo6.c freenodes.c ft_atoi.c \
		ft_split.c ft_strdup.c ft_strjoin.c \
		ft_strlen.c join_split.c linked_list.c \
		moves.c moves2.c moves3.c print_moves.c \
		print_moves2.c print_moves3.c push_swap.c main.c
		
BNSSRC = algo.c algo2.c algo3.c algo4.c \
		algo5.c algo6.c freenodes.c ft_atoi.c \
		ft_split.c ft_strdup.c ft_strjoin.c \
		ft_strlen.c join_split.c linked_list.c \
		moves.c moves2.c moves3.c print_moves.c \
		print_moves2.c print_moves3.c checker.c \
		GNL/get_next_line.c GNL/get_next_line_utils.c \
		push_swap.c
		
BNS = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

bonus: $(BNS)

$(BNS): $(BNSSRC) $(HEADER)
	$(CC) $(CFLAGS) -o $(BNS) $(BNSSRC)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BNS_OBJ)

fclean: clean
	@rm -f $(NAME) $(BNS)

re: fclean all

.PHONY: all clean fclean re

