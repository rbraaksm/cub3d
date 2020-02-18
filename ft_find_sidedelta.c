/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 15:39:53 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	ft_find_hit(t_vars *v)
{
	int		hit;
	int		side;

	hit = 0;
	v->mapx = v->map->posx;
	v->mapy = v->map->posy;
	printf("--------------------------------\n");
	print(v);
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
	printf("\n");
	if (side == 0)
	{
		// afstand is hier side_x;
		printf("X_HIT\n");
	}
	else
	{
		printf("Y_HIT\n");
	}
	print(v);
	printf("--------------------------------\n");
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
	v->sidex = fabs(x / sin(v->angle));
	v->sidey = fabs(y / cos(v->angle));
	v->deltax = fabs(v->tile_w / sin(v->angle));
	v->deltay = fabs(v->tile_h / cos(v->angle));
	if (v->rayx < 0)
		v->stepx = 1;
	else
		v->stepx = -1;
	if (v->rayy < 0)
		v->stepy = -1;
	else
		v->stepy = 1;
	ft_find_hit(v);
}