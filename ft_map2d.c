/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map2d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:13:44 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/04 14:30:52 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	my_mlx_pixel_put(t_vars *v, int x, int y, int color)
{
	char	*dst;

	dst = v->addr + (y * v->line_length + x * (v->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	printblock(t_vars *v, int row, int column)
{
	int				x;
	int				y;

	y = row * v->tile_h;
	while (y < ((row * v->tile_h) + v->tile_h))
	{
		x = column * v->tile_w;
		while (x < ((column * v->tile_w) + v->tile_w))
		{
			if (v->map->map[row][column] == '1')
				my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			else if (v->map->map[row][column] == '2')
				my_mlx_pixel_put(v, x, y, 0x00FF7F);
			x++;
		}
		y++;
	}
}

void	make_grid(t_vars *v)
{
	int		r;
	int		c;

	r = 0;
	while (r < v->map->row)
	{
		c = 0;
		while (c < v->map->column)
		{
			if (v->map->map[r][c] == '1' || v->map->map[r][c] == '2')
				printblock(v, r, c);
			if (v->map->map[r][c] == 'N')
			{
				// v->player->play_y = r * v->tile_h + (v->tile_h / 2);
				// v->player->play_x = c * v->tile_w + (v->tile_w / 2);
				v->player->y = r  + 0.5;
				v->player->x = c + 0.5;
			}
			c++;
		}
		r++;
	}
}

void	ft_make_2d(t_vars *v)
{
	make_grid(v);
	player(v, 0, 0x00BFFF);
	mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
}
