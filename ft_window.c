/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/05 13:56:47 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		action(t_vars *v)
{
	if (v->player->move_l)
		player(v, 0.05);
	if (v->player->move_r)
		player(v, -0.05);
	if (v->player->move_f)
		player(v, -0.05);
	if (v->player->move_b)
		player(v, 0.05);
	if (v->player->rotate_l)
		ft_view(v, 0.03);
	if (v->player->rotate_r)
		ft_view(v, -0.03);
	return (0);
}

int		keyrelease(int keycode, t_vars *v)
{
	if (keycode == 0)
		v->player->move_l = 0;
	if (keycode == 1)
		v->player->move_b = 0;
	if (keycode == 2)
		v->player->move_r = 0;
	if (keycode == 13)
		v->player->move_f = 0;
	if (keycode == 123)
		v->player->rotate_l = 0;
	if (keycode == 124)
		v->player->rotate_r = 0;
	return (0);
}

int		keypress(int keycode, t_vars *v)
{
	// printf("[keycode] %d\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(v->g->mlx, v->g->win);
	if (keycode == 0)
		v->player->move_l = 1;
	if (keycode == 1)
		v->player->move_b = 1;
	if (keycode == 2)
		v->player->move_r = 1;
	if (keycode == 13)
		v->player->move_f = 1;
	if (keycode == 123)
		v->player->rotate_l = 1;
	if (keycode == 124)
		v->player->rotate_r = 1;
	return (0);
}

void	get_info(t_vars *v, t_flags *d, t_color *color, t_map *map)
{
	t_texture	*textures;
	t_player	*player;
	t_ray		*ray;
	t_game		*g;

	g = (t_game *)malloc(sizeof(t_game) * 1);
	if (g == NULL)
		return ;
	ray = (t_ray *)malloc(sizeof(t_ray) * 1);
	if (ray == NULL)
		return ;
	textures = (t_texture *)malloc(sizeof(t_texture) * 1);
	if (textures == NULL)
		return ;
	player = (t_player *)malloc(sizeof(t_player) * 1);
	if (player == NULL)
		return ;
	v->g = g;
	v->map = map;
	v->d = d;
	v->color = *color;
	v->player = player;
	v->ray = ray;
	v->textures = textures;
	struct_info(v);
}

int		make_img(t_vars *v)
{
	v->g->win = mlx_new_window(v->g->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->g->img1 = mlx_new_image(v->g->mlx, v->d->resx, v->d->resy);
	v->g->img2 = mlx_new_image(v->g->mlx, v->d->resx, v->d->resy);
	v->g->addr = mlx_get_data_addr(v->g->img1, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
	return (1);
}

void	window(t_flags *d, t_color *color, t_map *map)
{
	t_vars	v;
	int		check;

	check = 0;
	get_info(&v, d, color, map);
	v.g->mlx = mlx_init();
	make_img(&v);
	mlx_hook(v.g->win, 2, 1L << 0, keypress, &v);
	mlx_hook(v.g->win, 3, 1L << 1, keyrelease, &v);
	mlx_loop_hook(v.g->mlx, &action, &v);
	mlx_loop(v.g->mlx);
}
