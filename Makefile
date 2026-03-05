# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:08:12 by marvin            #+#    #+#              #
#    Updated: 2024/11/29 19:56:40 by gmechaly         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wextra -Wall -Werror -g
NAME = push_swap
INCLUDES = includes/
SRC = actualize.c combined_move_tools.c frees.c inits.c main.c moves_tools.c \
	moves_tools2.c parsing.c push_swap.c tools.c stack_tools2.c moves.c stack_tools.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = mylibft/
LIBFT = mylibft/libft.a
LIBFT_H = mylibft/includes/

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I $(LIBFT_H)

$(LIBFT) :
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean fclean re all
