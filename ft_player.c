/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/19 16:01:29 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	player(t_vars *v, double move, char d, unsigned int color)
{
	float		x;
	float		y;

	if (d == 'h')
	{
		x = move * cos(v->angle);
		y = move * sin(v->angle);
	}
	else
	{
		x = -(move * sin(v->angle));
		y = move * cos(v->angle);
	}
	if (v->map->map[(int)((v->play_y - y) / v->tile_h)][(int)((v->play_x + x) / v->tile_w)] != '1')
	{
		ft_view(v, 0, 0x000000, 'c');
		v->play_x += x;
		v->play_y -= y;
		my_mlx_pixel_put(v, v->play_x, v->play_y, color);
		v->map->posy = (int)(v->play_y / v->tile_h);
		v->map->posx = (int)(v->play_x / v->tile_w);
		ft_view(v, 0, 0xFFE4E1, ' ');
	}
}
