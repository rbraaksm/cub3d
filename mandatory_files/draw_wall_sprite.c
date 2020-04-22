/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall_sprite.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 14:18:17 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_wall(t_vars *v)
{
	v->c = 0;
	if (v->ray.dist < 0.15)
		v->ray.dist = 0.15;
	v->height = v->resy / v->ray.dist;
	v->f = v->height / 2 + v->resy / 2;
	v->start = -v->height / 2 + v->resy / 2;
	v->middle = v->start;
	while (v->c < v->middle)
	{
		my_mlx_pixel_put(v, v->x, v->c, v->ceiling);
		v->c++;
	}
	while (v->middle < v->f)
	{
		my_image_put(v, (v->xperc * v->img_width[v->tex]),
		(v->yperc * v->img_height[v->tex]));
		v->middle++;
		v->yperc = (v->middle - v->start) / v->height;
	}
	while (v->f < v->resy)
	{
		my_mlx_pixel_put(v, v->x, v->f, v->floor);
		v->f++;
	}
}
