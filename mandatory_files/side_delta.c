/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   side_delta.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 14:10:41 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wall_data(t_vars *v, int side)
{
	if (side == 1)
	{
		v->tex = 2;
		v->ray.dist = v->ray.sidey * cos(fabs(v->ray.angle - v->ray.playdir));
		if (v->ray.rayx < 0)
			v->xperc = v->player.x - fabs(v->ray.rayx * v->ray.sidey);
		else
			v->xperc = v->player.x + fabs(v->ray.rayx * v->ray.sidey);
		if (v->ray.rayy < 0)
			v->tex = 0;
	}
	else
	{
		v->tex = 1;
		v->ray.dist = v->ray.sidex * cos(fabs(v->ray.angle - v->ray.playdir));
		if (v->ray.rayy < 0)
			v->xperc = v->player.y - fabs(v->ray.rayy * v->ray.sidex);
		else
			v->xperc = v->player.y + fabs(v->ray.rayy * v->ray.sidex);
		if (v->ray.rayx < 0)
			v->tex = 3;
	}
	v->xperc -= (int)v->xperc;
	return (1);
}

static int	new_sidedist(t_vars *v, int side, int mapy, int mapx)
{
	if (v->map[mapy][mapx] == '2')
		sprite(v, side, mapy, mapx);
	if (v->map[mapy][mapx] == '1')
		return ((wall_data(v, side) == 1));
	if (side == 0)
		v->ray.sidex += v->ray.deltax;
	else
		v->ray.sidey += v->ray.deltay;
	return (0);
}

void		find_hit(t_vars *v)
{
	int		side;
	int		mapx;
	int		mapy;

	mapx = v->player.x;
	mapy = v->player.y;
	while (1)
	{
		if (v->ray.sidex < v->ray.sidey)
		{
			side = 0;
			mapx += v->stepx;
		}
		else
		{
			mapy += v->stepy;
			side = 1;
		}
		if (new_sidedist(v, side, mapy, mapx) == 1)
			break ;
	}
}

void		find_side_delta(t_vars *v)
{
	float	x;
	float	y;

	if (v->ray.playdir > (0.5 * M_PI) && v->ray.playdir < (1.5 * M_PI))
		y = v->player.y - (int)v->player.y;
	else
		y = 1 - (v->player.y - (int)v->player.y);
	if (v->ray.playdir > M_PI && v->ray.playdir < (M_PI * 2))
		x = v->player.x - (int)v->player.x;
	else
		x = 1 - (v->player.x - (int)v->player.x);
	v->ray.sidex = fabs(x / v->ray.rayx);
	v->ray.sidey = fabs(y / v->ray.rayy);
	if (v->ray.rayx < 0)
		v->stepx = -1;
	else
		v->stepx = 1;
	if (v->ray.rayy < 0)
		v->stepy = -1;
	else
		v->stepy = 1;
	find_hit(v);
}
