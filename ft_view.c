/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/05 11:37:32 by rbraaksm      ########   odam.nl         */
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

void	raydistance(t_vars *v)
{
	if (v->ray->raydist == 0)
	{
		v->ray->adjust = 1 / atan(M_PI / 6);
		v->ray->raydist = (v->ray->opp / (float)v->d->resx) * 2;
		return ;
	}
	v->ray->opp -= v->ray->raydist;
	v->ray->playdir = v->ray->angle + atan(v->ray->opp / v->ray->adjust);
}

void	ft_cleanview(t_vars *v)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	v->ray->angle = v->ray->playdir;
	while (i <= v->d->resx)
	{
		x = v->player->x * v->tile_w;
		y = v->player->y * v->tile_h;
		while (my_mlx_pixel_putwall(v, x, y, 0x000000) == 1)
		{
			x += sin(v->ray->playdir);
			y += cos(v->ray->playdir);
		}
		raydistance(v);
		i++;
	}
	v->ray->playdir = v->ray->angle;
	v->ray->opp = 1;
}

void	ft_view(t_vars *v, float rot, unsigned int color)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	if (v->ray->playdir < 0)
		v->ray->playdir += (2 * M_PI);
	if (v->ray->playdir > (2 * M_PI))
		v->ray->playdir -= (2 * M_PI);
	ft_cleanview(v);
	make_grid(v);
	v->ray->playdir += rot;
	v->ray->angle = v->ray->playdir;
	while (i <= v->d->resx)
	{
		x = v->player->x * v->tile_w;
		y = v->player->y * v->tile_h;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(v->ray->playdir);
			y += cos(v->ray->playdir);
		}
		ft_find_sidedelta(v);
		raydistance(v);
		ft_find_length(v, i);
		i++;
	}
	v->ray->playdir = v->ray->angle;
	v->ray->opp = 1;
	if (v->g->active_img == 1)
	{
		mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img1, 0, 0);
			mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
		v->g->addr = mlx_get_data_addr(v->g->img2, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
		v->g->active_img = 2;
	}
	else
	{
		mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img2, 0, 0);
			mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
		v->g->addr = mlx_get_data_addr(v->g->img1, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
		v->g->active_img = 1;
	}
}
