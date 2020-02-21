/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/21 13:54:52 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	calc_distance(t_vars *v, int side)
{
	// print(v);
	if (side == 0)
	{
		v->walldist = cos(v->playdir - v->angle) * v->sidex;
		printf("X: %f\n", v->walldist);
		// print(v);
	}
	else
	{
		v->walldist = cos(v->playdir - v->angle) * v->sidey;
		printf("Y: %f\n", v->walldist);
	}
	printf("\n");
}

void	find_hit(t_vars *v)
{
	int		side;

	v->map->posy = (int)(v->play_y / v->tile_h);
	v->map->posx = (int)(v->play_x / v->tile_w);
	v->mapx = v->map->posx;
	v->mapy = v->map->posy;
	while (1)
	{
		if (v->sidex < v->sidey)
		{
			side = 0;
			v->mapx = v->mapx + v->stepx;
			if (v->map->map[v->mapy][v->mapx] == '1')
				break ;
			v->sidex += v->deltax;
		}
		else
		{
			v->mapy += v->stepy;
			side = 1;
			if (v->map->map[v->mapy][v->mapx] == '1')
			{
				break ;
			}
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

	printf("[angle] %f\n", v->angle);
	if (v->angle > (0.5 * M_PI) && v->angle < (1.5 * M_PI))
		y = v->play_y - ((double)v->map->posy * v->tile_h);
	else
		y = (v->tile_h * ((double)v->map->posy + 1)) - v->play_y;
	if (v->angle > M_PI && v->angle < (M_PI * 2))
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
	printf("[X] %f\n", x);
	printf("[Y] %f\n", y);
	printf("[POSX] %d\n", v->map->posx);
	printf("[POSy] %d\n", v->map->posy);
	print(v);
	printf("[STEPX] %d\n", v->stepx);
	printf("[STEPY] %d\n", v->stepy);
	printf("[MAPX] %d\n", v->mapx);
	printf("[MAPY] %d\n", v->mapy);
	find_hit(v);
}