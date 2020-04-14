/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:37:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 13:32:10 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_values(t_vars *v, int mapx, int mapy)
{
	v->s->middle_x = (float)mapx + 0.5;
	v->s->middle_y = (float)mapy + 0.5;
	v->s->x_hit = v->player->x + (v->ray->finaldist * v->ray->rayx);
	v->s->y_hit = v->player->y + (v->ray->finaldist * v->ray->rayy);
	v->s->angle = v->ray->playdir + (M_PI / 2);
	v->s->x_angle = sin(v->s->angle);
	v->s->y_angle = cos(v->s->angle);
	if (v->ray->sidey < v->ray->sidex)
	{
		v->s->schuin = 0.5 / cos(v->s->angle);
		v->s->y_hit_angle = v->s->y_hit;
		if (v->ray->playdir > (M_PI * 0.5) && v->ray->playdir < (M_PI * 1.5))
			v->s->x_hit_angle = v->s->middle_x + (v->s->schuin * v->s->x_angle);
		else
			v->s->x_hit_angle = v->s->middle_x - (v->s->schuin * v->s->x_angle);
	}
	else
	{
		v->s->schuin = 0.5 / sin(v->s->angle);
		v->s->x_hit_angle = v->s->x_hit;
		if (v->ray->playdir < M_PI && v->ray->playdir > 0)
			v->s->y_hit_angle = v->s->middle_y - (v->s->schuin * v->s->y_angle);
		else
			v->s->y_hit_angle = v->s->middle_y + (v->s->schuin * v->s->y_angle);
	}
}

void	sprite_hit(t_vars *v, int side)
{
	if (side == 0)
	{
		if (v->ray->rayx >= 0)
			v->ray->sprite_hit = 1;
		else
			v->ray->sprite_hit = 3;
		v->ray->finaldist = v->ray->sidex;
	}
	else
	{
		if (v->ray->rayy >= 0)
			v->ray->sprite_hit = 2;
		else
			v->ray->sprite_hit = 0;
		v->ray->finaldist = v->ray->sidey;
	}
}

int		sprite_data(t_vars *v, int side, int mapy, int mapx)
{
	sprite_hit(v, side);
	sprite_values(v, mapx, mapy);
	v->s->x_incr = (v->s->x_angle / v->s->y_angle) * 0.001;
	v->s->x_angle_incr = (v->ray->rayx / v->ray->rayy) * 0.001;
	v->s->y_incr = (v->s->y_angle / v->s->x_angle) * 0.001;
	v->s->y_angle_incr = (v->ray->rayy / v->ray->rayx) * 0.001;
	if (v->ray->sprite_hit == 0)
		sprite_north(v);
	else if (v->ray->sprite_hit == 1)
		sprite_east(v);
	else if (v->ray->sprite_hit == 2)
		sprite_south(v);
	else if (v->ray->sprite_hit == 3)
		sprite_west(v);
	v->s->finaldist[v->index] *= cos(fabs(v->ray->angle - v->ray->playdir));
	if (v->s->perc[v->index] > 1 || v->s->perc[v->index] < 0)
		return (0);
	v->ray->sprite = 1;
	v->index++;
	return (1);
}
