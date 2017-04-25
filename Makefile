# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunniet <ecunniet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 23:03:00 by ecunniet          #+#    #+#              #
#    Updated: 2017/04/25 12:00:59 by ecunniet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
INC = -I includes/
POINTH = fractol.h \
	libft/libft.h
LIB = libft/libft.a
MLX = -L minilibx_macos/
CC = gcc
SRC = ft_error.c ft_algo_fractal.c main.c ft_hook_keyboard.c \
	ft_hook_mouse.c
OBJ= $(SRC:%.c=%.o)

all: $(NAME) 

$(NAME):
	$(MAKE) -C libft/
	$(CC) -c $(SRC) $(INC)
	$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIB) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C libft/

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C libft/

re: fclean
	$(MAKE) all

norme:
	@norminette $(SRC) $(POINTH)
	@norminette libft/

.PHONY: all clean fclean re norme
