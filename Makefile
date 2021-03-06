# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atikhono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/01 17:15:51 by atikhono          #+#    #+#              #
#    Updated: 2018/05/12 21:04:19 by atikhono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBNAME = ./libft/libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wfatal-errors

#-Wall -Wextra -Werror

MLX = -lmlx -framework AppKit -framework OpenGL  

SRC =	main.c\
		line.c\
		parser.c\
		hookers.c\
		map.c

all: liball $(NAME)

obj: $(OBJ)

$(NAME) : $(LIBNAME) $(OBJ)
		gcc -O3 $(FLAGS) $^ -o $(NAME) $(MLX)

%.o: %.c
		gcc $(FLAGS) -o $@ -c $<

clean: libclean
		rm -rf $(OBJ)

fclean: libfclean clean
		rm -rf $(NAME)

re: fclean all

$(LIBNAME): liball

liball:
	@make -C ./libft all

libclean:
	@make -C ./libft clean

libfclean:
	@make -C ./libft fclean

libre: libfclean liball
