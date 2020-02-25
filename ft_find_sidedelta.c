/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/25 13:08:54 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	side_hit(t_vars *v, int side)
{
	if (side == 0)
	{
		if (v->rayx >= 0)
			v->side_hit = 1;
		else
			v->side_hit = 3;
	}
	else
	{
		if (v->rayy > 0)
			v->side_hit = 0;
		else
			v->side_hit = 2;
	}
}

void	calc_distance(t_vars *v, int side)
{
	side_hit(v, side);
	if (side == 0)
		v->walldist = cos(v->angle - v->playdir) * v->sidex;
	else
		v->walldist = cos(v->angle - v->playdir) * v->sidey;
}

void	find_hit(t_vars *v)
{
	int		side;
	int		mapx;
	int		mapy;

	mapx = v->map->posx;
	mapy = v->map->posy;
	while (1)
	{
		if (v->sidex < v->sidey)
		{
			side = 0;
			mapx += v->stepx;
			if (v->map->map[mapy][mapx] == '1' ||
			v->map->map[mapy][mapx] == '2')
				break ;
			v->sidex += v->deltax;
		}
		else
		{
			mapy += v->stepy;
			side = 1;
			if (v->map->map[mapy][mapx] == '1' ||
			v->map->map[mapy][mapx] == '2')
				break ;
			v->sidey += v->deltay;
		}
	}
	calc_distance(v, side);
}

void	calc_info(t_vars *v, float x, float y)
{
	v->rayx = sin(v->playdir);
	v->rayy = cos(v->playdir);
	v->sidex = fabs(x / v->rayx);
	v->sidey = fabs(y / v->rayy);
	v->deltax = fabs(v->tile_w / v->rayx);
	v->deltay = fabs(v->tile_h / v->rayy);
}

void	ft_find_sidedelta(t_vars *v)
{
	float	x;
	float	y;

	if (v->playdir < 0)
		v->playdir += (2 * M_PI);
	if (v->playdir > (2 * M_PI))
		v->playdir -= (2 * M_PI);
	if (v->playdir > (0.5 * M_PI) && v->playdir < (1.5 * M_PI))
		y = v->play_y - ((float)v->map->posy * v->tile_h);
	else
		y = (v->tile_h * ((float)v->map->posy + 1)) - v->play_y;
	if (v->playdir > M_PI && v->playdir < (M_PI * 2))
		x = v->play_x - ((float)v->map->posx * v->tile_w);
	else
		x = (v->tile_w * ((float)v->map->posx + 1)) - v->play_x;
	calc_info(v, x, y);
	if (v->rayx < 0)
		v->stepx = -1;
	else
		v->stepx = 1;
	if (v->rayy < 0)
		v->stepy = -1;
	else
		v->stepy = 1;
	find_hit(v);
}