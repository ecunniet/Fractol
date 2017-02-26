# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecunniet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 16:43:23 by ecunniet          #+#    #+#              #
#    Updated: 2017/02/05 22:05:55 by ecunniet         ###   ########.fr        #
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
SRC = ft_error.c algo_fractal.c 

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
	@$(MAKE) norme -C libft/

.PHONY: all clean fclean re norme
