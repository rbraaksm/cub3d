/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map2d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:13:44 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/21 09:29:36 by rbraaksm      ########   odam.nl         */
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

static void	printblock(t_vars *v, int row, int column)
{
	int				x;
	int				y;

	y = row * v->tile_h;
	while (y < ((row * v->tile_h) + v->tile_h))
	{
		x = column * v->tile_w;
		while (x < ((column * v->tile_w) + v->tile_w))
		{
			if (v->MAP[row][column] == '1')
				my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			else if (v->MAP[row][column] == '2')
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
			if (v->MAP[r][c] == '1' || v->MAP[r][c] == '2')
				printblock(v, r, c);
			if (v->MAP[r][c] == 'N' || v->MAP[r][c] == 'E' || v->MAP[r][c] == 'S' ||
				v->MAP[r][c] == 'W')
			{
				v->player->y = r + 0.5;
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
	player(v, 0, 0xffffff);
	mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
}