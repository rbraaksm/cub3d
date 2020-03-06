/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/06 10:13:17 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	calc_distance(t_vars *v, t_ray *ray, int side)
{
	if (side == 0)
	{
		ray->walldist = cos(ray->angle - ray->playdir) * ray->sidex;
		if (v->ray->rayx >= 0)
			v->ray->side_hit = 1;
		else
			v->ray->side_hit = 3;
		v->ray->finaldist = v->ray->sidex;
	}
	else
	{
		ray->walldist = cos(ray->angle - ray->playdir) * ray->sidey;
		if (v->ray->rayy > 0)
			v->ray->side_hit = 2;
		else
			v->ray->side_hit = 0;
		v->ray->finaldist = v->ray->sidey;
	}
}

void	find_hit(t_vars *v)
{
	int		side;
	int		mapx;
	int		mapy;

	mapx = v->player->x;
	mapy = v->player->y;
	while (1)
	{
		if (v->ray->sidex < v->ray->sidey)
		{
			side = 0;
			mapx += v->stepx;
			if (v->map->map[mapy][mapx] == '1' ||
			v->map->map[mapy][mapx] == '2')
				break ;
			v->ray->sidex += v->ray->deltax;
		}
		else
		{
			mapy += v->stepy;
			side = 1;
			if (v->map->map[mapy][mapx] == '1' ||
			v->map->map[mapy][mapx] == '2')
				break ;
			v->ray->sidey += v->ray->deltay;
		}
	}
	calc_distance(v, v->ray, side);
}

void	calc_info(t_vars *v, float x, float y)
{
	v->ray->sidex = fabs(x / v->ray->rayx);
	v->ray->sidey = fabs(y / v->ray->rayy);
	v->ray->deltax = fabs(1 / v->ray->rayx);
	v->ray->deltay = fabs(1/ v->ray->rayy);
}

void	ft_find_sidedelta(t_vars *v)
{
	float	x;
	float	y;

	if (v->ray->playdir > (0.5 * M_PI) && v->ray->playdir < (1.5 * M_PI))
		y = v->player->y - (int)v->player->y;
	else
		y = 1 - (v->player->y - (int)v->player->y);
	if (v->ray->playdir > M_PI && v->ray->playdir < (M_PI * 2))
		x = v->player->x - (int)v->player->x;
	else
		x = 1 - (v->player->x - (int)v->player->x);
	calc_info(v, x, y);
	if (v->ray->rayx < 0)
		v->stepx = -1;
	else
		v->stepx = 1;
	if (v->ray->rayy < 0)
		v->stepy = -1;
	else
		v->stepy = 1;
	find_hit(v);
}