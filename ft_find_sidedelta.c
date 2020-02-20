/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/20 17:36:30 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	calc_distance(t_vars *v, int side)
{
	if (side == 0)
	{
		v->walldist = cos(v->playdir - v->tmpdir) * v->sidex;
		// printf("X: %f\n", v->walldist);
		// print(v);
	}
	else
	{
		v->walldist = cos(v->playdir - v->tmpdir) * v->sidey;
		// printf("Y: %f\n", v->walldist);
	}
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
			if (v->map->map[v->mapy][v->mapx] != '0')
				break ;
			v->sidex += v->deltax;
		}
		else
		{
			side = 1;
			v->mapy += v->stepy;
			if (v->map->map[v->mapy][v->mapx] != '0')
				break ;
			v->sidey += v->deltay;
		}
	}
	calc_distance(v, side);
}

void	calc_info(t_vars *v, double x, double y)
{
	v->rayx = sin(v->tmpdir);
	v->rayy = cos(v->tmpdir);
	v->sidex = fabs(x / v->rayx);
	v->sidey = fabs(y / v->rayy);
	v->deltax = fabs(v->tile_w / v->rayx);
	v->deltay = fabs(v->tile_h / v->rayy);
}

void	ft_find_sidedelta(t_vars *v)
{
	double	x;
	double	y;

	if (v->tmpdir > (0.5 * M_PI) && v->tmpdir < (1.5 * M_PI))
		y = v->play_y - ((double)v->map->posy * v->tile_h);
	else
		y = (v->tile_h * ((double)v->map->posy + 1)) - v->play_y;
	if (v->tmpdir > M_PI && v->tmpdir < (M_PI * 2))
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