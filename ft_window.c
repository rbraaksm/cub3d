/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/13 21:05:38 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_values(t_vars *v)
{
	if (v->POS == 'N')
		v->ray->playdir = M_PI;
	else if (v->POS == 'E')
		v->ray->playdir = M_PI * 0.5;
	else if (v->POS == 'S')
		v->ray->playdir = 0;
	else if (v->POS == 'W')
		v->ray->playdir = M_PI * 1.5;
	v->ray->raydist = 0;
	v->player->move_f = 0;
	v->player->move_b = 0;
	v->player->move_l = 0;
	v->player->move_r = 0;
	v->player->rotate_r = 0;
	v->player->rotate_l = 0;
	v->active_img = 1;
	SPRITE_I = 0;
	start_game(v);
}

void	get_info(t_vars *v)
{
	t_tex	n_tex;
	t_tex	e_tex;
	t_tex	s_tex;
	t_tex	w_tex;
	t_tex	sprite;

	north_texture(v, v->d->no, &n_tex);
	east_texture(v, v->d->ea, &e_tex);
	south_texture(v, v->d->so, &s_tex);
	west_texture(v, v->d->we, &w_tex);
	sprite_texture(v, v->d->s, &sprite);
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
