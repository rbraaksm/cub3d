# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 14:09:57 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/04/15 21:16:13 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
MLX		= libmlx.dylib

SRCS =	ft_main.c \
		check_input.c \
		ft_make_string.c \
		fill_parser.c \
		data_strings.c \
		data_res_color.c \
		make_map.c \
		check_grid.c \
		utils.c \
		ft_window.c \
		keypress.c \
		start_exit_game.c \
		ft_view.c \
		ft_player.c \
		ft_find_sidedelta.c \
		draw_wall_sprite.c \
		draw_pixel_image.c \
		screenshot.c \
		texture_data.c \
		sprite_data.c \
		sprite_hit.c \

LIB		=	$(SRCS:%.c=%.o)
SRCS2	=	$(addprefix mandatory_files/,$(SRCS))

CC = gcc -O3 -Wall -Werror -Wextra -std=gnu99 -I minilibx -L minilibx -lmlx \
	-framework OpenGL -framework AppKit -g -o

all: $(NAME)

$(MLX):
	make -C minilibx
	cp -r minilibx/$(MLX) .

$(NAME):	$(MLX)
			$(CC) $(NAME) $(SRCS2)

clean:
	# make -C minilibx clean
	/bin/rm -f $(LIB)
	/bin/rm -f $(NAME) $(MLX)
	/bin/rm -f screenshot.bmp

fclean: clean

re: fclean all
