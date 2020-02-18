/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 17:18:23 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	calc_distance(t_vars *v, int side)
{
	if (side == 0)
		v->walldist = (v->mapx - v->map->posx + (1 - v->stepx) / 2) / v->rayx;
	else
		v->walldist = (v->mapy - v->map->posy + (1 - v->stepy) / 2) / v->rayy;
	print(v);
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
	v->sidex = fabs(x / v->rayx);
	v->sidey = fabs(y / v->rayy);
	v->deltax = fabs(v->tile_w / v->rayx);
	v->deltay = fabs(v->tile_h / v->rayy);
}

void	ft_find_sidedelta(t_vars *v)
{
	double	x;
	double	y;

	if (v->angle > (0.5 * M_PI) && v->angle < (1.5 * M_PI))
		y = (int)v->play_y % (int)v->tile_h;
	else
		y = v->tile_h - ((int)v->play_y % (int)v->tile_h);
	if (v->angle > M_PI)
		x = (int)v->play_x % (int)v->tile_w;
	else
		x = v->tile_w - ((int)v->play_x % (int)v->tile_w);
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