# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 14:09:57 by rbraaksm       #+#    #+#                 #
#    Updated: 2020/03/09 10:26:25 by rbraaksm      ########   odam.nl          #
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
		ft_map2d.c \
		ft_view.c \
		ft_player.c \
		ft_find_sidedelta.c \
		ft_textures.c \
		ft_sprite.c \
		ft_draw.c \
		ft_struct.c \
		ft_2d.c \
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
