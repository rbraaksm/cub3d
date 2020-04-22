# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rbraaksm <rbraaksm@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/22 14:09:57 by rbraaksm      #+#    #+#                  #
#    Updated: 2020/04/22 09:40:26 by rbraaksm      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
MLX		= libmlx.dylib

SRCS =	cub3d.c \
		check_input.c \
		read_cubfile.c \
		fill_parser.c \
		data_strings.c \
		data_res_color.c \
		make_map.c \
		check_map.c \
		utils.c \
		keypress.c \
		game_start.c \
		game_exit.c \
		rays.c \
		player.c \
		side_delta.c \
		draw_wall_sprite.c \
		draw_pixel_image.c \
		screenshot.c \
		sprite.c \

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
	make -C minilibx clean
	/bin/rm -f screenshot.bmp

fclean: clean
		/bin/rm -f $(LIB)
		/bin/rm -f $(NAME)
		/bin/rm -f $(MLX)


re: fclean all
