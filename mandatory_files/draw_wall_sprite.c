/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall_sprite.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 17:02:58 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void		draw_floor_ceiling(t_vars *v, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		my_mlx_pixel_put(v, v->i, index, v->d->ceiling);
		index++;
	}
	index = v->d->resy;
	while (index > count)
	{
		my_mlx_pixel_put(v, v->i, index, v->d->floor);
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
	// float	y;

	length = ((1 / v->ray->walldist) * v->d->resy);
	count = (length / 2) + (v->d->resy / 2);
	tmpcount = count;
	draw_floor_ceiling(v, count);
	// v->tex = find_texture(v);
	if (v->ray->walldist <= 0.2)
		v->ray->walldist = 0.2;
	v->height = v->d->resy / v->ray->walldist;
	v->end = v->height / 2 + v->d->resy / 2;
	v->start = -v->height / 2 + v->d->resy / 2;
	v->dest_y = v->start;
	// v->perc_x = (float)v->iw[v->ray->side_hit] * get_perc(v);
	while (v->dest_y < v->end)
	{
		x = v->perc_x * v->iw[v->tex];
		y = v->perc_y * v->ih[v->tex];
		my_image_put(v, x, y);
		v->dest_y++;
		v->perc_y = (v->dest_y - v->start) / v->height;
	}

	// tex->y_tex = tex->height - 1;
	// y = (float)tex->height / (float)length;
	// while (length > 0)
	// {
	// 	my_image_put(v, tex, v->i, count);
	// 	count--;
	// 	length--;
	// 	tex->y_tex -= y;
	// }
}

void			draw_sprite(t_vars *v)
{
	float	x;
	float	y;

	while (v->index > 0)
	{
		v->s[v->index].dist = fabs(sqrt(pow(v->player->y - v->s[v->index].cen_y, 2) +
		pow(v->player->x - v->s[v->index].cen_x, 2)) * cos(fabs(v->ray->angle - v->ray->playdir)));
		v->height = (float)v->d->resy / v->s[v->index].dist;
		v->end = v->height / 2 + v->d->resy / 2;
		v->start = -v->height / 2 + v->d->resy / 2;
		v->dest_y = v->start;
		x = v->s[v->index].x * v->iw[4];
		while (v->dest_y < v->end)
		{
			v->perc_y = fabs(((float)v->dest_y - v->start) / v->height);
			y = v->perc_y * v->ih[4];
			my_mlx_pixel_put_sprite(v, x, y);
			v->dest_y++;
		}
		v->index--;
	}
}
