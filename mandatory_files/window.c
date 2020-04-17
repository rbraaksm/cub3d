/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/17 13:02:18 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	struct_values(t_vars *v)
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
	v->active_img = 2;
	v->index = 0;
	start_game(v);
}

void		get_info(t_vars *v)
{
	t_tex	n_tex;
	t_tex	e_tex;
	t_tex	s_tex;
	t_tex	w_tex;
	t_tex	sprite;

	v->check += north_texture(v, v->d->no, &n_tex);
	v->check += east_texture(v, v->d->ea, &e_tex);
	v->check += south_texture(v, v->d->so, &s_tex);
	v->check += west_texture(v, v->d->we, &w_tex);
	v->check += sprite_texture(v, v->d->s, &sprite);
	if (v->check != 5)
		exit_game(v);
	struct_values(v);
}

void		window(t_vars *v)
{
	t_texture	textures;
	t_player	player;
	t_ray		ray;
	t_sprite	s;

	v->textures = &textures;
	v->player = &player;
	v->ray = &ray;
	v->s = &s;
	get_info(v);
}
