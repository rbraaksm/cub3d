/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/05 13:53:11 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

static void	raydistance(t_vars *v)
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

void	ft_view(t_vars *v, float rot)
{
	int		i;

	i = 0;
	if (v->ray->playdir < 0)
		v->ray->playdir += (2 * M_PI);
	if (v->ray->playdir > (2 * M_PI))
		v->ray->playdir -= (2 * M_PI);
	v->ray->playdir += rot;
	v->ray->angle = v->ray->playdir;
	while (i <= v->d->resx)
	{
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
		v->g->addr = mlx_get_data_addr(v->g->img2, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
		v->g->active_img = 2;
	}
	else
	{
		mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img2, 0, 0);
		v->g->addr = mlx_get_data_addr(v->g->img1, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
		v->g->active_img = 1;
	}
}
