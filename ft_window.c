/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/15 18:05:51 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_values(t_vars *v)
{
	if (v->d->position == 'N')
		v->ray->playdir = M_PI;
	else if (v->d->position == 'E')
		v->ray->playdir = M_PI * 0.5;
	else if (v->d->position == 'S')
		v->ray->playdir = 0;
	else if (v->d->position == 'W')
		v->ray->playdir = M_PI * 1.5;
	v->ray->adjust = 1 / atan(M_PI / 6);
	v->player->x = v->d->play_x;
	v->player->y = v->d->play_y;
	v->ray->raydist = 0;
	v->active_img = 1;
	v->index = 0;
	start_game(v);
}

void	get_info(t_vars *v)
{
	t_tex	n_tex;
	t_tex	e_tex;
	t_tex	s_tex;
	t_tex	w_tex;
	t_tex	sprite;

	v->screen_x = 0;
	v->screen_y = 0;
	v->check = 0;
	mlx_get_screen_size(v->mlx, &v->screen_x, &v->screen_y);
	if (v->d->resx > v->screen_x && v->d->save != 1)
		v->d->resx = v->screen_x;
	if (v->d->resy > v->screen_y && v->d->save != 1)
		v->d->resy = v->screen_y;
	v->check += north_texture(v, v->d->no, &n_tex);
	v->check += east_texture(v, v->d->ea, &e_tex);
	v->check += south_texture(v, v->d->so, &s_tex);
	v->check += west_texture(v, v->d->we, &w_tex);
	v->check += sprite_texture(v, v->d->s, &sprite);
	if (v->check != 5)
		exit_game(v);
	struct_values(v);
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
	v.d = d;
	get_info(&v);
}
