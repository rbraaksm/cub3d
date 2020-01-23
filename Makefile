# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 14:09:57 by rbraaksm       #+#    #+#                 #
#    Updated: 2020/01/23 15:29:57 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	ft_main.c \
		ft_make_string.c \
		ft_mapindex.c \
		ft_result_colors.c \
		ft_atoi.c \
		ft_split.c \
		ft_fill_grid.c \
		ft_check_grid.c \
		ft_window.c \
		print.c \

LIB = $(SRCS:%.c=%.o)

CC = gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit
	
$(NAME):
	$(CC) $(SRCS)

clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
