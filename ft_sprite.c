/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 08:06:55 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/10 09:06:31 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

static void	draw_roof(t_vars *v, int count)
{
	int				index;

	index = 0;
	while (index < count)
	{
		my_mlx_pixel_put2(v, v->i, index, v->color.ceiling);
		index++;
	}
}

static void	draw_floor(t_vars *v, int count)
{
	int				index;

	index = v->d->resy;
	while (index > count)
	{
		my_mlx_pixel_put2(v, v->i, index, v->color.floor);
		index--;
	}
}

static float	get_perc(t_vars *v)
{
	float	x_cord;
	float	y_cord;
	float	perc;

	x_cord = v->player->x + v->ray->finaldist * v->ray->rayx;
	y_cord = v->player->y + v->ray->finaldist * v->ray->rayy;
	if (v->ray->side_hit == 0 || v->ray->side_hit == 2)
		perc = x_cord - (int)x_cord;
	else
		perc = y_cord - (int)y_cord;
	return (perc);
}

void	draw_sprite(t_vars *v)
{
	t_tex	*tex;
	float	length;
	float	count;
	float	tmpcount;
	float	y;

	tex = v->textures->sprite;
	length = ((1 / v->ray->walldist) * (v->d->resy - 1));
	count = (length / 2) + (v->d->resy / 2);
	tmpcount = count;
	draw_roof(v, count);
	tex->x_tex = (float)tex->width * get_perc(v);
	tex->y_tex = tex->height;
	y = (float)tex->height / (float)length;
	while (length >= 0)
	{
		my_image_put(v, tex, v->i, count);
		count--;
		length--;
		tex->y_tex -= y;
	}
	draw_floor(v, tmpcount);
}