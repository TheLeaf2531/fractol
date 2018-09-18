# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/07 17:11:05 by vboissel          #+#    #+#              #
#    Updated: 2018/09/18 14:26:23 by vboissel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGSMLIB = -lmlx -framework OpenGL -framework AppKit
LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
SRC = $(wildcard ./sources/*.c)
HDR = $(wildcard ./headers/*.h)
INC = ./headers/
INC_MLX = /usr/local/include

all : $(NAME)

$(NAME): $(SRC) $(HDR)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(FLAGSMLIB) -I $(INC) -I $(LIBFT_DIR) $(LIBFT) $(SRC) -o "fractol"

clean :
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean : clean
	@(cd $(LIBFT_DIR) && $(MAKE) $@)
	@rm -f $(NAME)

re : fclean all

.phony : $(NAME)
