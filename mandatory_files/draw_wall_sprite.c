/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall_sprite.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 18:51:41 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		draw_floor_ceiling(t_vars *v, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		my_mlx_pixel_put(v, v->x, index, v->ceiling);
		index++;
	}
	index = v->resy;
	while (index > count)
	{
		my_mlx_pixel_put(v, v->x, index, v->floor);
		index--;
	}
}

void			draw_wall(t_vars *v)
{
	int		x;
	int		y;
	float	length;
	float	count;
	float	tmpcount;

	length = ((1 / v->ray.walldist) * v->resy);
	count = (length / 2) + (v->resy / 2);
	tmpcount = count;
	draw_floor_ceiling(v, count);
	if (v->ray.walldist < 0.2)
		v->ray.walldist = 0.2;
	v->height = v->resy / v->ray.walldist;
	v->end = v->height / 2 + v->resy / 2;
	v->start = -v->height / 2 + v->resy / 2;
	v->dest_y = v->start;
	while (v->dest_y < v->end)
	{
		x = v->perc_x * v->img_width[v->tex];
		y = v->perc_y * v->img_height[v->tex];
		my_image_put(v, x, y);
		v->dest_y++;
		v->perc_y = (v->dest_y - v->start) / v->height;
	}
}

void			draw_sprite(t_vars *v)
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
		v->dest_y = v->start;
		x = v->s[v->si].perc * v->img_width[4];
		while (v->dest_y < v->end)
		{
			v->perc_y = fabs(((float)v->dest_y - v->start) / v->height);
			y = v->perc_y * v->img_height[4];
			my_mlx_pixel_put_sprite(v, x, y);
			v->dest_y++;
		}
		v->si--;
	}
}
