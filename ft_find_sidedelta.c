/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/19 18:11:21 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	calc_distance(t_vars *v, int side)
{
	if (side == 0)
		v->walldist = v->sidex;
	else
		v->walldist = v->sidey;
}

void	find_hit(t_vars *v)
{
	int		side;

	v->mapx = v->map->posx;
	v->mapy = v->map->posy;
	while (1)
	{
		if (v->sidex < v->sidey)
		{
			side = 0;
			v->mapx += v->stepx;
			if (v->map->map[v->mapy][v->mapx] == '1')
				break ;
			v->sidex += v->deltax;
		}
		else
		{
			side = 1;
			v->mapy += v->stepy;
			if (v->map->map[v->mapy][v->mapx] == '1')
				break ;
			v->sidey += v->deltay;
		}
	}
	calc_distance(v, side);
}

void	calc_info(t_vars *v, double x, double y)
{
	v->rayx = sin(v->angle);
	v->rayy = cos(v->angle);
	v->sidex = fabs(x / sin(v->angle));
	v->sidey = fabs(y / cos(v->angle));
	v->deltax = fabs(v->tile_w / sin(v->angle));
	v->deltay = fabs(v->tile_h / cos(v->angle));
}

void	ft_find_sidedelta(t_vars *v)
{
	double	x;
	double	y;

	if (v->angle > (0.5 * M_PI) && v->angle < (1.5 * M_PI))
		y = v->play_y - ((double)v->map->posy * v->tile_h);
	else
		y = (v->tile_h * ((double)v->map->posy + 1)) - v->play_y;
	if (v->angle > M_PI)
		x = v->play_x - ((double)v->map->posx * v->tile_w);
	else
		x = (v->tile_w * ((double)v->map->posx + 1)) - v->play_x;
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