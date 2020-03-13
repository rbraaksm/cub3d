/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 08:06:55 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 11:15:45 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	draw_sprite(t_vars *v)
{
	t_tex	*tex;
	float	length;
	float	count;
	float	y;

	tex = v->textures->sprite;
	length = (v->d->resy / v->s->finaldist);
	count = (length / 2) + (v->d->resy / 2);
	tex->x_tex = (float)tex->width * v->s->perc;
	tex->y_tex = tex->height - 1;
	y = (float)tex->height / (float)length;
	while (length > 0)
	{
		my_sprite_put(v, tex, v->i, count);
		count--;
		length--;
		tex->y_tex -= y;
	}
}
