/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_2d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/05 13:00:09 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/05 13:40:06 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

static void	make_grid(t_vars *v)
{
	int		x;
	int		y;
	int		z;

	z = 0;
	y = v->tile_h;
	while (z < v->map->row)
	{
		x = 0;
		while (x < v->d->resx)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			x++;
		}
		y += v->tile_h;
		z++;
	}
	x = v->tile_w;
	z = 0;
	while (z < v->map->column)
	{
		y = 0;
		while (y < v->d->resy)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			y++;
		}
		x += v->tile_w;
		z++;
	}
}

static float	raydistance(t_vars *v, float angle)
{
	if (v->ray->raydist == 0)
	{
		v->ray->adjust = 1 / atan(M_PI / 6);
		v->ray->raydist = (v->ray->opp / (float)v->d->resx) * 2;
	}
	v->ray->opp -= v->ray->raydist;
	angle = v->ray->angle + atan(v->ray->opp / v->ray->adjust);
	return (angle);
}

void	ft_cleanview(t_vars *v, float angle)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	v->ray->angle = angle;
	while (i <= v->d->resx)
	{
		x = v->player->x * v->tile_w;
		y = v->player->y * v->tile_h;
		while (my_mlx_pixel_putwall(v, x, y, 0x000000) == 1)
		{
			x += sin(angle);
			y += cos(angle);
		}
		angle = raydistance(v, angle);
		i++;
	}
	angle = v->ray->angle;
	v->ray->opp = 1;
}

void	make2d(t_vars *v, float rot, unsigned int color)
{
	int		i;
	float	x;
	float	y;
	float	angle;

	i = 0;
	angle = v->ray->playdir;
	ft_cleanview(v, angle);
	make_grid(v);
	angle += rot;
	v->ray->angle = angle;
	while (i <= v->d->resx)
	{
		x = v->player->x * v->tile_w;
		y = v->player->y * v->tile_h;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(angle);
			y += cos(angle);
		}
		angle = raydistance(v, angle);
		i++;
	}
	angle = v->ray->angle;
	v->ray->opp = 1;
}