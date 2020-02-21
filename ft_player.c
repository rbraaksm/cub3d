/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/21 13:08:41 by rbraaksm      ########   odam.nl         */
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
	if (v->map->map[(int)((v->play_y - y) / v->tile_h)][(int)((v->play_x + x) / v->tile_w)] != '1' &&
		v->map->map[(int)((v->play_y - y) / v->tile_h)][(int)((v->play_x + x) / v->tile_w)] != '2')
	{
		ft_view(v, 0, 0x000000, 'c');
		v->play_x += x;
		v->play_y -= y;
		my_mlx_pixel_put(v, v->play_x, v->play_y, color);
		v->map->posy = (v->play_y / (double)v->tile_h);
		v->map->posx = (v->play_x / (double)v->tile_w);
		ft_view(v, 0, 0xFFE4E1, ' ');
	}
}
