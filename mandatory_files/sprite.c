/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:37:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 09:40:40 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_side_1_up_right(t_vars *v)
{
	float i;

	v->s[v->index].all_x = v->s[v->index].cen_x + 0.5 * tan(v->s[v->index].angle);
	i = (v->s[v->index].all_x - v->s[v->index].hitx) /
	(v->s[v->index].incr_ray + v->s[v->index].incr_spr);
	v->s[v->index].hity -= i * 0.001;
	v->s[v->index].hitx += i * v->s[v->index].incr_ray;
	v->s[v->index].end_sprx = v->s[v->index].cen_x + fabs(v->s[v->index].dirx / 2);
	v->s[v->index].x = 1 - fabs((v->s[v->index].hitx - v->s[v->index].end_sprx)
	/ v->s[v->index].dirx);
}

void	sprite_side_0_up_right(t_vars *v)
{
	float i;

	v->s[v->index].all_y = v->s[v->index].cen_y - 0.5 / tan(v->s[v->index].angle);
	i = (-v->s[v->index].all_y + v->s[v->index].hity) / (v->s[v->index].incr_spr +
	v->s[v->index].incr_ray);
	v->s[v->index].hitx += i * 0.001;
	v->s[v->index].hity -= i * v->s[v->index].incr_spr;
	v->s[v->index].end_spry = v->s[v->index].cen_y - fabs(v->s[v->index].diry / 2);
	v->s[v->index].x = fabs((v->s[v->index].hity - v->s[v->index].end_spry) /
	v->s[v->index].diry);
}

void	sprite_side_1_up_left(t_vars *v)
{
	float i;

	v->s[v->index].all_x = v->s[v->index].cen_x + 0.5 * tan(v->s[v->index].angle);
	i = (-v->s[v->index].all_x + v->s[v->index].hitx) / (v->s[v->index].incr_ray +
	v->s[v->index].incr_spr);
	v->s[v->index].hity -= i * 0.001;
	v->s[v->index].hitx -= i * v->s[v->index].incr_ray;
	v->s[v->index].end_sprx = v->s[v->index].cen_x - fabs(v->s[v->index].dirx / 2);
	v->s[v->index].x = fabs((v->s[v->index].hitx - v->s[v->index].end_sprx) /
	v->s[v->index].dirx);
}

void	sprite_side_0_down_right(t_vars *v)
{
	float i;

	v->s[v->index].all_y = v->s[v->index].cen_y + 0.5 / tan(v->s[v->index].angle);
	i = (v->s[v->index].all_y - v->s[v->index].hity) / (v->s[v->index].incr_spr +
	v->s[v->index].incr_ray);
	v->s[v->index].hitx -= i * 0.001;
	v->s[v->index].hity += i * v->s[v->index].incr_spr;
	v->s[v->index].end_spry = v->s[v->index].cen_y + fabs(v->s[v->index].diry / 2);
	v->s[v->index].x = fabs((v->s[v->index].hity - v->s[v->index].end_spry) /
	v->s[v->index].diry);
}

void	sprite_side_1_down_right(t_vars *v)
{
	float i;

	v->s[v->index].all_x = v->s[v->index].cen_x - 0.5 * tan(v->s[v->index].angle);
	i = (-v->s[v->index].all_x + v->s[v->index].hitx) / (v->s[v->index].incr_ray +
	v->s[v->index].incr_spr);
	v->s[v->index].hity += i * 0.001;
	v->s[v->index].hitx -= i * v->s[v->index].incr_ray;
	v->s[v->index].end_sprx = v->s[v->index].cen_x - fabs(v->s[v->index].dirx / 2);
	v->s[v->index].x = 1 - fabs((v->s[v->index].hitx - v->s[v->index].end_sprx) /
	v->s[v->index].dirx);
}

void	sprite_side_0_up_left(t_vars *v)
{
	float i;

	v->s[v->index].all_y = v->s[v->index].cen_y + 0.5 / tan(v->s[v->index].angle);
	i = (-v->s[v->index].all_y + v->s[v->index].hity) / (v->s[v->index].incr_spr +
	v->s[v->index].incr_ray);
	v->s[v->index].hitx -= i * 0.001;
	v->s[v->index].hity -= i * v->s[v->index].incr_spr;
	v->s[v->index].end_spry = v->s[v->index].cen_y - fabs(v->s[v->index].diry / 2);
	v->s[v->index].x = 1 - fabs((v->s[v->index].hity - v->s[v->index].end_spry) /
	v->s[v->index].diry);
}

void	sprite_side_1_down_left(t_vars *v)
{
	float i;

	v->s[v->index].all_x = v->s[v->index].cen_x - 0.5 * tan(v->s[v->index].angle);
	i = (v->s[v->index].all_x - v->s[v->index].hitx) / (v->s[v->index].incr_ray +
	v->s[v->index].incr_spr);
	v->s[v->index].hity += i * 0.001;
	v->s[v->index].hitx += i * v->s[v->index].incr_ray;
	v->s[v->index].end_sprx = v->s[v->index].cen_x + fabs(v->s[v->index].dirx / 2);
	v->s[v->index].x = fabs((v->s[v->index].hitx - v->s[v->index].end_sprx) /
	v->s[v->index].dirx);
}

void	sprite_side_0_down_left(t_vars *v)
{
	float i;

	v->s[v->index].all_y = v->s[v->index].cen_y - 0.5 / tan(v->s[v->index].angle);
	i = (v->s[v->index].all_y - v->s[v->index].hity) / (v->s[v->index].incr_spr +
	v->s[v->index].incr_ray);
	v->s[v->index].hitx += i * 0.001;
	v->s[v->index].hity += i * v->s[v->index].incr_spr;
	v->s[v->index].end_spry = v->s[v->index].cen_y + fabs(v->s[v->index].diry / 2);
	v->s[v->index].x = 1 - fabs((v->s[v->index].hity - v->s[v->index].end_spry) /
	v->s[v->index].diry);
}

int		sprite_data(t_vars *v, int side, int mapy, int mapx)
{
	v->index++;
	if (side == 0)
	{
		v->s[v->index].hity = v->ray->sidex * v->ray->rayy + v->player->y;
		v->s[v->index].hitx = v->ray->sidex * v->ray->rayx + v->player->x;
	}
	else
	{
		v->s[v->index].hity = v->ray->sidey * v->ray->rayy + v->player->y;
		v->s[v->index].hitx = v->ray->sidey * v->ray->rayx + v->player->x;
	}
	v->s[v->index].angle = v->ray->playdir - M_PI / 2;
	if (v->s[v->index].angle < 0)
		v->s[v->index].angle += M_PI * 2;
	v->s[v->index].cen_x = mapx + 0.5;
	v->s[v->index].cen_y = mapy + 0.5;
	v->s[v->index].dirx = sin(v->s[v->index].angle);
	v->s[v->index].diry = cos(v->s[v->index].angle);
	v->s[v->index].incr_spr = fabs(v->s[v->index].dirx / v->s[v->index].diry * 0.001);
	v->s[v->index].incr_ray = fabs(v->ray->rayx / v->ray->rayy * 0.001);
	if (side == 0)
	{
		if (v->ray->rayy > 0 && v->ray->rayx < 0)
			sprite_side_0_down_right(v);
		if (v->ray->rayy > 0 && v->ray->rayx > 0)
			sprite_side_0_down_left(v);
		if (v->ray->rayy < 0 && v->ray->rayx > 0)
			sprite_side_0_up_right(v);
		if (v->ray->rayy < 0 && v->ray->rayx < 0)
			sprite_side_0_up_left(v);
	}
	else
	{
		if (v->ray->rayy > 0 && v->ray->rayx < 0)
			sprite_side_1_down_right(v);
		if (v->ray->rayy > 0 && v->ray->rayx > 0)
			sprite_side_1_down_left(v);
		if (v->ray->rayy < 0 && v->ray->rayx > 0)
			sprite_side_1_up_right(v);
		if (v->ray->rayy < 0 && v->ray->rayx < 0)
			sprite_side_1_up_left(v);
	}
	return (1);
}
