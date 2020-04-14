/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_hit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:56:50 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 13:31:36 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_north(t_vars *v)
{
	if (v->s->x_angle_incr > 0)
	{
		while (v->s->x_hit > v->s->x_hit_angle)
		{
			v->s->x_hit -= v->s->x_angle_incr;
			v->s->x_hit_angle -= v->s->x_incr;
		}
	}
	else
	{
		while (v->s->x_hit < v->s->x_hit_angle)
		{
			v->s->x_hit -= v->s->x_angle_incr;
			v->s->x_hit_angle -= v->s->x_incr;
		}
	}
	v->s->start = v->s->middle_x - (fabs(v->s->x_angle) / 2);
	v->s->perc[v->index] = (v->s->x_hit - v->s->start) / fabs(v->s->x_angle);
	v->s->finaldist[v->index] = fabs(sqrt(pow(v->s->middle_x - v->player->x, 2)
	+ pow(v->s->middle_y - v->player->y, 2)));
}

void	sprite_east(t_vars *v)
{
	if (v->s->x_angle_incr < 0)
	{
		while (v->s->y_hit > v->s->y_hit_angle)
		{
			v->s->y_hit += v->s->y_angle_incr;
			v->s->y_hit_angle += v->s->y_incr;
		}
	}
	else
	{
		while (v->s->y_hit < v->s->y_hit_angle)
		{
			v->s->y_hit += v->s->y_angle_incr;
			v->s->y_hit_angle += v->s->y_incr;
		}
	}
	v->s->start = v->s->middle_y - (fabs(v->s->y_angle) / 2);
	v->s->perc[v->index] = ((v->s->y_hit - v->s->start) / fabs(v->s->y_angle));
	v->s->finaldist[v->index] = fabs(sqrt(pow(v->s->middle_y - v->player->y, 2)
	+ pow(v->s->middle_x - v->player->x, 2)));
}

void	sprite_south(t_vars *v)
{
	if (v->s->x_angle_incr > 0)
	{
		while (v->s->x_hit < v->s->x_hit_angle)
		{
			v->s->x_hit += v->s->x_angle_incr;
			v->s->x_hit_angle += v->s->x_incr;
		}
	}
	else
	{
		while (v->s->x_hit > v->s->x_hit_angle)
		{
			v->s->x_hit += v->s->x_angle_incr;
			v->s->x_hit_angle += v->s->x_incr;
		}
	}
	v->s->start = v->s->middle_x - (fabs(v->s->x_angle) / 2);
	v->s->perc[v->index] = 1 - ((v->s->x_hit - v->s->start) /
	fabs(v->s->x_angle));
	v->s->finaldist[v->index] = fabs(sqrt(pow(v->s->middle_x - v->player->x, 2)
	+ pow(v->s->middle_y - v->player->y, 2)));
}

void	sprite_west(t_vars *v)
{
	if (v->s->x_angle_incr < 0)
	{
		while (v->s->y_hit < v->s->y_hit_angle)
		{
			v->s->y_hit -= v->s->y_angle_incr;
			v->s->y_hit_angle -= v->s->y_incr;
		}
	}
	else
	{
		while (v->s->y_hit > v->s->y_hit_angle)
		{
			v->s->y_hit -= v->s->y_angle_incr;
			v->s->y_hit_angle -= v->s->y_incr;
		}
	}
	v->s->start = v->s->middle_y - (fabs(v->s->y_angle) / 2);
	v->s->perc[v->index] = 1 - ((v->s->y_hit - v->s->start) /
	fabs(v->s->y_angle));
	v->s->finaldist[v->index] = fabs(sqrt(pow(v->s->middle_y - v->player->y, 2)
	+ pow(v->s->middle_x - v->player->x, 2)));
}
