/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 17:18:49 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		my_mlx_pixel_putwall(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (v->map->map[y / (int)v->tile_h][x / (int)v->tile_w] == '1' ||
		v->map->map[y / (int)v->tile_h][x / (int)v->tile_w] == '2')
		return (0);
	else
	{
		dst = v->addr + (y * v->line_length + x *
		(v->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		return (1);
	}
}

static void	make_grid(t_vars *v)
{
	int		x;
	int		y;
	int		z;

	z = 0;
	y = v->tile_h;
	while (z < v->map->row)
	{
		x = 0;
		while (x < v->data->resx)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			x++;
		}
		y += v->tile_h;
		z++;
	}
	x = v->tile_w;
	z = 0;
	while (z < v->map->column)
	{
		y = 0;
		while (y < v->data->resy)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			y++;
		}
		x += v->tile_w;
		z++;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
}

void	ft_view(t_vars *v, double rot, unsigned int color, char c)
{
	double	x;
	double	y;
	double	tmp;

	if (v->angle < 0)
		v->angle += (2 * M_PI);
	if (v->angle > (2 * M_PI))
		v->angle -= (2 * M_PI);
	if (c == 'c')
		ft_view(v, 0, 0x000000, ' ');
	make_grid(v);
	v->angle += rot;
	tmp = v->angle;
	// v->angle -= 0.25;
	// while (v->angle > (tmp - 0.26) && v->angle < (tmp + 0.26))
	// {
		x = v->play_x;
		y = v->play_y;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(v->angle);
			y += cos(v->angle);
		}
	// 	v->angle += 0.001;
	// }
	// v->angle = tmp;
	ft_find_sidedelta(v);
}