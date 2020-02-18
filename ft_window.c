/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 16:48:55 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

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

int		keycode(int keycode, t_vars *v)
{
	// printf("[keycode] %d\n", keycode);
	make_grid(v);
	if (keycode == 53)
		mlx_destroy_window(v->mlx, v->win);
	if (keycode == 0)
		player(v, 5.0, 'h', 0x00BFFF);
	if (keycode == 1)
		player(v, 5.0, 'v', 0x00BFFF);
	if (keycode == 2)
		player(v, -5.0, 'h', 0x00BFFF);
	if (keycode == 13)
		player(v, -5.0, 'v', 0x00BFFF);
	if (keycode == 123)
		ft_view(v, 0.1, 0xFFE4E1, 'c');
	if (keycode == 124)
		ft_view(v, -0.1, 0xFFE4E1, 'c');
	mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
	return (keycode);
}

void	get_info(t_vars *v)
{
	v->angle = M_PI;
	v->tile_w = v->data->resx / v->map->column;
	v->tile_h = v->data->resy / v->map->row;
	v->rayx = sin(v->angle);
	v->rayy = cos(v->angle);
}

void	window(t_flags *data, t_color *color, t_map *map)
{
	t_vars	v;

	v.map = map;
	v.data = data;
	v.color = color;
	get_info(&v);
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, data->resx, data->resy, "CUB3D");

		/* KEYCODE*/
	mlx_hook(v.win, 2, 1L<<0, keycode, &v);

	v.mapimg = mlx_new_image(v.mlx, data->resx, data->resy);
	v.addr = mlx_get_data_addr(v.mapimg, &v.bits_per_pixel, &v.line_length, &v.endian);

	/* make 2D map */
	ft_make_2d(&v);

	/* find side/delta */
	// ft_find_sidedelta(&v);
	mlx_loop(v.mlx);
}
