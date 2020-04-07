/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/07 15:02:07 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		exit_game(t_vars *v)
{
	int	i;

	i = 0;
	if (!v->win)
		mlx_destroy_window(v->mlx, v->win);
	while (v->MAP[i])
	{
		free(v->MAP[i]);
		i++;
	}
	exit(0);
	return (0);
}

int		action(t_vars *v)
{
	if (v->player->move_l)
		player(v, 0.08);
	if (v->player->move_r)
		player(v, -0.08);
	if (v->player->move_f)
		player(v, -0.08);
	if (v->player->move_b)
		player(v, 0.08);
	if (v->player->rotate_l)
		ft_view(v, 0.05);
	if (v->player->rotate_r)
		ft_view(v, -0.05);
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
	if (keycode == 53)
		exit_game(v);
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

void	get_info(t_vars *v, t_flags *d)
{
	v->d = d;
	struct_info(v);
}

int		make_img(t_vars *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->img1 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->img2 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->addr = mlx_get_data_addr(v->img1, &v->bits_per_pixel, &v->line_length, &v->endian);
	ft_make_2d(v);
	return (1);
}

void	start_game(t_vars *v)
{
	int		check;

	check = 0;
	if (check == 0)
		check = make_img(v);
	if (v->d->save == 1)
	{
		bmp(v);
		exit_game(v);
		return ;
	}
	mlx_hook(v->win, 2, 1L << 0, keypress, v);
	mlx_hook(v->win, 3, 1L << 1, keyrelease, v);
	mlx_hook(v->win, 17, 1L << 17, exit_game, v);
	mlx_loop_hook(v->mlx, &action, v);
	mlx_loop(v->mlx);
}

void	window(t_flags *d)
{
	t_vars		v;
	t_texture	textures;
	t_player	player;
	t_ray		ray;
	t_sprite	s;

	v.textures = &textures;
	v.player = &player;
	v.ray = &ray;
	v.s = &s;
	get_info(&v, d);
	start_game(&v);
}
