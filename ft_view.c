/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/15 12:21:26 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_img_2_win(t_vars *v)
{
	if (v->d->save == 1)
		v->active_img = 2;
	if (v->active_img == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win, v->img1, 0, 0);
		v->addr = mlx_get_data_addr(v->img2, &v->bits_per_pixel,
		&v->line_length, &v->endian);
		v->active_img = 2;
	}
	else
	{
		mlx_put_image_to_window(v->mlx, v->win, v->img2, 0, 0);
		v->addr = mlx_get_data_addr(v->img1, &v->bits_per_pixel,
		&v->line_length, &v->endian);
		v->active_img = 1;
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

void	check_dir(t_vars *v)
{
	if (v->ray->playdir < 0)
		v->ray->playdir += (2 * M_PI);
	if (v->ray->playdir > (2 * M_PI))
		v->ray->playdir -= (2 * M_PI);
}

void	ft_view(t_vars *v)
{
	v->i = 0;
	check_dir(v);
	v->ray->angle = v->ray->playdir;
	v->ray->opp = 1;
	while (v->i < v->d->resx)
	{
		raydistance(v);
		v->ray->sprite = 0;
		check_dir(v);
		find_side_delta(v);
		find_hit(v);
		draw_wall(v);
		if (v->index > 0)
			draw_sprite(v);
		v->i++;
	}
	v->ray->playdir = v->ray->angle;
	put_img_2_win(v);
}
