/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 14:55:17 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_2_window(t_vars *v)
{
	if (v->d->save == 1)
		v->img = 5;
	if (v->img == 5)
	{
		mlx_put_image_to_window(v->mlx, v->win, v->img1, 0, 0);
		v->img = 6;
	}
	else
	{
		mlx_put_image_to_window(v->mlx, v->win, v->img2, 0, 0);
		v->img = 5;
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
	v->x = v->d->resx;
	v->ray.angle = v->ray.playdir;
	while (v->x >= 0)
	{
		v->ray.playdir = v->ray.angle + atan(start / v->ray.adjust);
		check_dir(v);
		find_side_delta(v);
		draw_wall(v);
		if (v->si > 0)
			draw_sprite(v);
		start += incr;
		v->x--;
	}
	v->ray.playdir = v->ray.angle;
	put_2_window(v);
}
