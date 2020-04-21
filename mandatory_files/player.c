/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 10:34:13 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_vars *v, float rot)
{
	v->ray.playdir += rot;
	if (v->ray.playdir < 0)
		v->ray.playdir += (2 * M_PI);
	if (v->ray.playdir > (2 * M_PI))
		v->ray.playdir -= (2 * M_PI);
}

void	move_player(t_vars *v, float move)
{
	float temp_x;
	float temp_y;

	temp_x = v->player.x;
	temp_y = v->player.y;
	v->player.x += sin(v->ray.playdir) * move;
	if (v->d->map[(int)v->player.y][(int)v->player.x] == '1')
		v->player.x = temp_x;
	v->player.y += cos(v->ray.playdir) * move;
	if (v->d->map[(int)v->player.y][(int)v->player.x] == '1')
		v->player.y = temp_y;
}

void	crab_player(t_vars *v, float move)
{
	float temp_x;
	float temp_y;
	float x_dir;
	float y_dir;

	temp_x = v->player.x;
	temp_y = v->player.y;
	x_dir = sin(v->ray.playdir + M_PI / 2);
	y_dir = cos(v->ray.playdir + M_PI / 2);
	v->player.x += x_dir * move;
	if (v->d->map[(int)v->player.y][(int)v->player.x] == '1')
		v->player.x = temp_x;
	v->player.y += y_dir * move;
	if (v->d->map[(int)v->player.y][(int)v->player.x] == '1')
		v->player.y = temp_y;
}
