/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:37:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 14:30:49 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	north_sprite(t_vars *v)
{
	v->s[v->si].y_hit = v->ray.sidey * v->ray.rayy + v->player.y;
	v->s[v->si].x_hit = v->ray.sidey * v->ray.rayx + v->player.x;
	v->s[v->si].all = v->s[v->si].x - 0.5 * tan(v->s[v->si].angle);
	if (v->ray.rayy > 0 && v->ray.rayx < 0)
	{
		v->s[v->si].y_hit += ((-v->s[v->si].all + v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * 0.001);
		v->s[v->si].x_hit -=  ((-v->s[v->si].all + v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * v->s[v->si].y_incr);
		v->s[v->si].start = v->s[v->si].x - fabs(v->s[v->si].xdir / 2);
		v->s[v->si].perc = 1 - fabs((v->s[v->si].x_hit - v->s[v->si].start) /
		v->s[v->si].xdir);
	}
	else
	{
		v->s[v->si].y_hit += ((v->s[v->si].all - v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * 0.001);
		v->s[v->si].x_hit += ((v->s[v->si].all - v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * v->s[v->si].y_incr);
		v->s[v->si].start = v->s[v->si].x + fabs(v->s[v->si].xdir / 2);
		v->s[v->si].perc = fabs((v->s[v->si].x_hit - v->s[v->si].start) /
		v->s[v->si].xdir);
	}
}

static void	south_sprite(t_vars *v)
{
	v->s[v->si].y_hit = v->ray.sidey * v->ray.rayy + v->player.y;
	v->s[v->si].x_hit = v->ray.sidey * v->ray.rayx + v->player.x;
	v->s[v->si].all = v->s[v->si].x + 0.5 * tan(v->s[v->si].angle);
	if (v->ray.rayy < 0 && v->ray.rayx > 0)
	{
		v->s[v->si].y_hit -= ((v->s[v->si].all - v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * 0.001);
		v->s[v->si].x_hit += ((v->s[v->si].all - v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * v->s[v->si].y_incr);
		v->s[v->si].start = v->s[v->si].x + fabs(v->s[v->si].xdir / 2);
		v->s[v->si].perc = 1 - fabs((v->s[v->si].x_hit - v->s[v->si].start)
		/ v->s[v->si].xdir);
	}
	else
	{
		v->s[v->si].y_hit -= ((-v->s[v->si].all + v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * 0.001);
		v->s[v->si].x_hit -= ((-v->s[v->si].all + v->s[v->si].x_hit) /
		(v->s[v->si].y_incr + v->s[v->si].x_incr) * v->s[v->si].y_incr);
		v->s[v->si].start = v->s[v->si].x - fabs(v->s[v->si].xdir / 2);
		v->s[v->si].perc = fabs((v->s[v->si].x_hit - v->s[v->si].start) /
		v->s[v->si].xdir);
	}
}

static void	east_sprite(t_vars *v)
{
	v->s[v->si].y_hit = v->ray.sidex * v->ray.rayy + v->player.y;
	v->s[v->si].x_hit = v->ray.sidex * v->ray.rayx + v->player.x;
	v->s[v->si].all = v->s[v->si].y - 0.5 / tan(v->s[v->si].angle);
	if (v->ray.rayy > 0 && v->ray.rayx > 0)
	{
		v->s[v->si].x_hit += ((v->s[v->si].all - v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * 0.001);
		v->s[v->si].y_hit += ((v->s[v->si].all - v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * v->s[v->si].x_incr);
		v->s[v->si].start = v->s[v->si].y + fabs(v->s[v->si].ydir / 2);
		v->s[v->si].perc = 1 - fabs((v->s[v->si].y_hit - v->s[v->si].start) /
		v->s[v->si].ydir);
	}
	if (v->ray.rayy < 0 && v->ray.rayx > 0)
	{
		v->s[v->si].x_hit += ((-v->s[v->si].all + v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * 0.001);
		v->s[v->si].y_hit -= ((-v->s[v->si].all + v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * v->s[v->si].x_incr);
		v->s[v->si].start = v->s[v->si].y - fabs(v->s[v->si].ydir / 2);
		v->s[v->si].perc = fabs((v->s[v->si].y_hit - v->s[v->si].start) /
		v->s[v->si].ydir);
	}
}

static void	west_sprite(t_vars *v)
{
	v->s[v->si].y_hit = v->ray.sidex * v->ray.rayy + v->player.y;
	v->s[v->si].x_hit = v->ray.sidex * v->ray.rayx + v->player.x;
	v->s[v->si].all = v->s[v->si].y + 0.5 / tan(v->s[v->si].angle);
	if (v->ray.rayy > 0 && v->ray.rayx < 0)
	{
		v->s[v->si].x_hit -= ((v->s[v->si].all - v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * 0.001);
		v->s[v->si].y_hit += ((v->s[v->si].all - v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * v->s[v->si].x_incr);
		v->s[v->si].start = v->s[v->si].y + fabs(v->s[v->si].ydir / 2);
		v->s[v->si].perc = fabs((v->s[v->si].y_hit - v->s[v->si].start) /
		v->s[v->si].ydir);
	}
	if (v->ray.rayy < 0 && v->ray.rayx < 0)
	{
		v->s[v->si].x_hit -= ((-v->s[v->si].all + v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * 0.001);
		v->s[v->si].y_hit -= ((-v->s[v->si].all + v->s[v->si].y_hit) /
		(v->s[v->si].x_incr + v->s[v->si].y_incr) * v->s[v->si].x_incr);
		v->s[v->si].start = v->s[v->si].y - fabs(v->s[v->si].ydir / 2);
		v->s[v->si].perc = 1 - fabs((v->s[v->si].y_hit - v->s[v->si].start) /
		v->s[v->si].ydir);
	}
}

int			sprite(t_vars *v, int side, int mapy, int mapx)
{
	v->si++;
	v->s[v->si].angle = v->ray.playdir - M_PI / 2;
	if (v->s[v->si].angle < 0)
		v->s[v->si].angle += M_PI * 2;
	v->s[v->si].x = mapx + 0.5;
	v->s[v->si].y = mapy + 0.5;
	v->s[v->si].xdir = sin(v->s[v->si].angle);
	v->s[v->si].ydir = cos(v->s[v->si].angle);
	v->s[v->si].x_incr = fabs(v->s[v->si].xdir / v->s[v->si].ydir * 0.001);
	v->s[v->si].y_incr = fabs(v->ray.rayx / v->ray.rayy * 0.001);
	if (side == 0)
	{
		if (v->ray.rayx >= 0)
			east_sprite(v);
		else
			west_sprite(v);
	}
	else
	{
		if (v->ray.rayy < 0)
			south_sprite(v);
		else
			north_sprite(v);
	}
	return (1);
}
