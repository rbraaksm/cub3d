/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rays.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/23 15:21:48 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_2_window(t_vars *v)
{
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

static void	draw_sprite(t_vars *v)
{
	float	x;
	float	y;

	while (v->si > 0)
	{
		v->s[v->si].dist = fabs(sqrt(pow(v->player.y - v->s[v->si].y, 2) +
		pow(v->player.x - v->s[v->si].x, 2)) * cos(fabs(v->ray.angle -
		v->ray.playdir)));
		v->height = (float)v->resy / v->s[v->si].dist;
		v->end = v->height / 2 + v->resy / 2;
		v->start = -v->height / 2 + v->resy / 2;
		v->middle = v->start;
		x = v->s[v->si].perc * v->img_width[4];
		while (v->middle < v->end)
		{
			v->yperc = fabs(((float)v->middle - v->start) / v->height);
			y = v->yperc * v->img_height[4];
			my_mlx_pixel_put_sprite(v, x, y);
			v->middle++;
		}
		v->si--;
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
	incr = 2.0 / v->resx;
	v->x = v->resx;
	v->ray.angle = v->ray.playdir;
	while (v->x >= 0)
	{
		v->ray.playdir = v->ray.angle + atan(start / v->ray.adjust);
		check_dir(v);
		v->ray.rayx = sin(v->ray.playdir);
		v->ray.rayy = cos(v->ray.playdir);
		v->ray.deltax = fabs(1 / v->ray.rayx);
		v->ray.deltay = fabs(1 / v->ray.rayy);
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
