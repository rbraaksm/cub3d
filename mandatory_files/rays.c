/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 18:26:53 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_2_window(t_vars *v)
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

void		check_dir(t_vars *v)
{
	if (v->ray.playdir < 0)
		v->ray.playdir += (2 * M_PI);
	if (v->ray.playdir > (2 * M_PI))
		v->ray.playdir -= (2 * M_PI);
}

void		rays(t_vars *v)
{
	float	start;
	float	incr;

	start = -1;
	incr = 2.0 / v->d->resx;
	v->i = v->d->resx;
	v->ray.angle = v->ray.playdir;
	while (v->i >= 0)
	{
		v->ray.playdir = v->ray.angle + atan(start / v->ray.adjust);
		v->ray.sprite = 0;
		check_dir(v);
		find_side_delta(v);
		find_hit(v);
		draw_wall(v);
		if (v->index > 0)
			draw_sprite(v);
		start += incr;
		v->i--;
	}
	v->ray.playdir = v->ray.angle;
	put_2_window(v);
}
