/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/02 11:56:06 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		action(t_vars *v)
{
	if (v->move_l)
		player(v, 2, 0x00BFFF);
	if (v->move_r)
		player(v, -2, 0x00BFFF);
	if (v->move_f)
		player(v, -2, 0x00BFFF);
	if (v->move_b)
		player(v, 2, 0x00BFFF);
	if (v->rotate_l)
		ft_view(v, 0.03, 0xFFE4E1);
	if (v->rotate_r)
		ft_view(v, -0.03, 0xFFE4E1);
	return (0);
}

int		keyrelease(int keycode, t_vars *v)
{
	if (keycode == 0)
		v->move_l = 0;
	if (keycode == 1)
		v->move_b = 0;
	if (keycode == 2)
		v->move_r = 0;
	if (keycode == 13)
		v->move_f = 0;
	if (keycode == 123)
		v->rotate_l = 0;
	if (keycode == 124)
		v->rotate_r = 0;
	return (0);
}

int		keypress(int keycode, t_vars *v)
{
	// printf("[keycode] %d\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(v->mlx, v->win);
	if (keycode == 0)
		v->move_l = 1;
	if (keycode == 1)
		v->move_b = 1;
	if (keycode == 2)
		v->move_r = 1;
	if (keycode == 13)
		v->move_f = 1;
	if (keycode == 123)
		v->rotate_l = 1;
	if (keycode == 124)
		v->rotate_r = 1;
	if (keycode == 49)
	{
		mlx_put_image_to_window(v->textures->n_tex->mlx, v->g->win, v->textures->n_tex->img, 0, 0);
	}
	return (0);
}

void	get_info(t_vars *v, t_flags *d, t_color *color, t_map *map)
{
	t_texture *textures;

	textures = (t_texture *)malloc(sizeof(t_texture) * 1);
	if (textures == NULL)
		return ;
	textures->n_tex = texture_info(v, d->no);
	textures->e_tex = texture_info(v, d->ea);
	textures->s_tex = texture_info(v, d->so);
	textures->w_tex = texture_info(v, d->we);
	v->map = map;
	v->d = d;
	v->color = *color;
	v->playdir = 0;
	v->tile_w = v->d->resx / v->map->column;
	v->tile_h = v->d->resy / v->map->row;
	v->raydist = 0;
	v->opp = 1;
	v->move_f = 0;
	v->move_b = 0;
	v->move_l = 0;
	v->move_r = 0;
	v->rotate_r = 0;
	v->rotate_l = 0;
	v->g->active_img = 1;
	v->side_hit = 10;
	v->textures = textures;
}

int		make_img(t_vars *v)
{
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "MAP");
	v->g->win = mlx_new_window(v->g->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->mapimg = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->addr = mlx_get_data_addr(v->mapimg, &v->bits_per_pixel, &v->line_length, &v->endian);
	v->g->img1 = mlx_new_image(v->g->mlx, v->d->resx, v->d->resy);
	v->g->img2 = mlx_new_image(v->g->mlx, v->d->resx, v->d->resy);
	v->g->addr = mlx_get_data_addr(v->g->img1, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
	ft_make_2d(v);
	return (1);
}

void	window(t_flags *d, t_color *color, t_map *map)
{
	t_vars	v;
	t_game	g;
	int		check;

	check = 0;
	get_info(&v, d, color, map);
	v.g = &g;
	v.mlx = mlx_init();
	v.g->mlx = mlx_init();
	if (check == 0)
		check = make_img(&v);
	mlx_hook(g.win, 2, 1L << 0, keypress, &v);
	mlx_hook(g.win, 3, 1L << 1, keyrelease, &v);
	mlx_loop_hook(v.mlx, &action, &v);
	mlx_loop(v.mlx);
	mlx_loop(v.g->mlx);
}
