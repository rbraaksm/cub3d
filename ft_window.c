/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/23 14:19:17 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		keycode(int keycode, t_vars *v)
{
	// printf("[keycode] %d\n", keycode);
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
		ft_view(v, 0.1, 0xFFE4E1);
	if (keycode == 124)
		ft_view(v, -0.1, 0xFFE4E1);
	mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
	return (keycode);
}

void	get_info(t_vars *v)
{
	v->playdir = 0;
	v->tile_w = v->data->resx / v->map->column;
	v->tile_h = v->data->resy / v->map->row;
	v->raydist = 0;
	v->opp = 1;
	v->walldist = 0;
	v->test = v->color.ceiling;
}

void	window(t_flags *data, t_color *color, t_map *map)
{
	t_vars	v;

	v.map = map;
	v.data = data;
	v.color = *color;
	get_info(&v);
	v.mlx = mlx_init();
	v.game->mlx2 = mlx_init();
	v.win = mlx_new_window(v.mlx, data->resx, data->resy, "MAP");
	v.game->win2 = mlx_new_window(v.game->mlx2, data->resx, data->resy, "CUB3D");

		/* KEYCODE*/
	mlx_hook(v.win, 2, 1L<<0, keycode, &v);

	v.mapimg = mlx_new_image(v.mlx, data->resx, data->resy);
	v.addr = mlx_get_data_addr(v.mapimg, &v.bits_per_pixel, &v.line_length, &v.endian);
	v.game->mapimg2 = mlx_new_image(v.game->mlx2, data->resx, data->resy);
	v.game->addr2 = mlx_get_data_addr(v.game->mapimg2, &v.game->bits_per_pixel2, &v.game->line_length2, &v.game->endian2);

	/* make 2D map */
	ft_make_2d(&v);
	mlx_loop(v.mlx);
	mlx_loop(v.game->mlx2);
}
