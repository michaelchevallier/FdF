# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchevall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/26 14:43:40 by mchevall          #+#    #+#              #
#    Updated: 2016/02/24 17:42:20 by mchevall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIB = libft/libft.a
SRC =	main.c\
		ft_maptoint.c\
		on_esc_exit.c\
		absolute.c\
		ft_visualize.c\
		line_tracer.c
FLAG = -L /usr/lib -lmlx -framework OpenGl -framework AppKit -Wall -Werror -Wextra 

all: $(NAME)

$(NAME):
	make -C libft
	gcc -o $(NAME) $(SRC) $(FLAG) $(LIB) -I includes

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
