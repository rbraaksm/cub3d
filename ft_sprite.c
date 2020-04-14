/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 08:06:55 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 13:32:30 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_vars *v)
{
	float	length;
	float	count;
	float	y;

	while ((v->index - 1) > 0)
	{
		length = (v->d->resy / v->s->finaldist[v->index - 1]);
		count = (length / 2) + (v->d->resy / 2);
		v->textures->sprite->x_tex = (float)v->textures->sprite->width *
		v->s->perc[v->index - 1];
		v->textures->sprite->y_tex = v->textures->sprite->height - 1;
		y = (float)v->textures->sprite->height / (float)length;
		while (length > 0)
		{
			my_sprite_put(v, v->i, count);
			count--;
			length--;
			v->textures->sprite->y_tex -= y;
		}
		v->index--;
	}
}
