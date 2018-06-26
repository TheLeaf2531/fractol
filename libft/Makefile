# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboissel <vboissel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 18:22:57 by vboissel          #+#    #+#              #
#    Updated: 2018/03/29 17:48:28 by vboissel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = $(wildcard *.c)
INC = $(wildcard *.h)
OBJ = $(SRC:.c=.o)
GCH = $(wildcard *.gch)



all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean :
	@/bin/rm -f $(OBJ) $(GCH)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all


.SILENT : all $(NAME)

.phony : clean fclean
