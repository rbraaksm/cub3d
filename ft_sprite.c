/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_sprite.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 08:06:55 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/20 18:16:06 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	draw_sprite(t_vars *v, t_tex *tex)
{
	float	length;
	float	count;
	float	y;

	while ((SPRITE_I - 1) > 0)
	{
		length = (v->RESY / SPRITE_FINAL[SPRITE_I - 1]);
		count = (length / 2) + (v->RESY / 2);
		tex->x_tex = (float)tex->width * PERC[SPRITE_I - 1];
		tex->y_tex = tex->height - 1;
		y = (float)tex->height / (float)length;
		while (length > 0)
		{
			my_sprite_put(v, tex, v->i, count);
			count--;
			length--;
			tex->y_tex -= y;
		}
		SPRITE_I--;
	}
}
