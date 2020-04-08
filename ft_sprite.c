/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 08:06:55 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:12:02 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_vars *v)
{
	float	length;
	float	count;
	float	y;

	while ((SPRITE_I - 1) > 0)
	{
		length = (v->RESY / SPRITE_FINAL[SPRITE_I - 1]);
		count = (length / 2) + (v->RESY / 2);
		v->textures->sprite->x_tex = (float)v->textures->sprite->width *
		PERC[SPRITE_I - 1];
		v->textures->sprite->y_tex = v->textures->sprite->height - 1;
		y = (float)v->textures->sprite->height / (float)length;
		while (length > 0)
		{
			my_sprite_put(v, v->i, count);
			count--;
			length--;
			v->textures->sprite->y_tex -= y;
		}
		SPRITE_I--;
	}
}
