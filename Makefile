# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 14:09:57 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/04/08 15:58:10 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS =	ft_main.c \
		parser/check_input.c \
		parser/ft_make_string.c \
		parser/fill_parser.c \
		parser/data_strings.c \
		parser/data_res_color.c \
		parser/make_map.c \
		parser/check_grid.c \
		parser/tools/ft_atoi.c \
		ft_window.c \
		keypress.c \
		start_exit_game.c \
		ft_view.c \
		ft_player.c \
		ft_find_sidedelta.c \
		ft_textures.c \
		ft_sprite.c \
		ft_draw.c \
		screenshot.c \
		texture_data.c \
		sprite_data.c \
		sprite_hit.c \

LIB = $(SRCS:%.c=%.o)

CC = gcc -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

$(NAME):
	$(CC) $(SRCS)

clean:
	/bin/rm -f $(LIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
