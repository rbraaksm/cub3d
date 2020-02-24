/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/24 14:20:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		keycode(int keycode, t_vars *v)
{
	int		h;
	int		w;

	h = 0;
	w = 0;
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
	if (keycode == 49)
	{
		v->game->mlx3 = mlx_init();
		v->game->mapimg3 = mlx_xpm_file_to_image(v->game->mlx3, v->data->so, &w, &h);
		v->game->addr3 = mlx_get_data_addr(v->game->mapimg3, &v->game->bits_per_pixel3, &v->game->line_length3, &v->game->endian3);
		mlx_put_image_to_window(v->game->mlx3, v->game->win2, v->game->mapimg3, 0, 0);
	}
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
}

int	make_img(t_vars *v)
{
	v->win = mlx_new_window(v->mlx, v->data->resx, v->data->resy, "MAP");
	v->game->win2 = mlx_new_window(v->game->mlx2, v->data->resx, v->data->resy, "CUB3D");
	v->mapimg = mlx_new_image(v->mlx, v->data->resx, v->data->resy);
	v->addr = mlx_get_data_addr(v->mapimg, &v->bits_per_pixel, &v->line_length, &v->endian);
	v->game->mapimg2 = mlx_new_image(v->game->mlx2, v->data->resx, v->data->resy);
	v->game->addr2 = mlx_get_data_addr(v->game->mapimg2, &v->game->bits_per_pixel2, &v->game->line_length2, &v->game->endian2);
	ft_make_2d(v);
	return (1);
}

void	window(t_flags *data, t_color *color, t_map *map)
{
	t_vars	v;
	int		check;

	check = 0;
	v.map = map;
	v.data = data;
	v.color = *color;
	get_info(&v);
	v.mlx = mlx_init();
	v.game->mlx2 = mlx_init();
	if (check == 0)
		check = make_img(&v);
	mlx_hook(v.win, 2, 1L<<0, keycode, &v);
	mlx_loop(v.mlx);
	mlx_loop(v.game->mlx2);
}
