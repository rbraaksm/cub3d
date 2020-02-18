/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 15:10:49 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	raydir(t_vars *v, char d)
{
	if (d == 'h')
	{
		v->rayx = cos(v->angle);
		v->rayy = sin(v->angle);
	}
	else
	{
		v->rayx = -sin(v->angle);
		v->rayy = cos(v->angle);
	}
}

void	player(t_vars *v, double move, char d, unsigned int color)
{
	int		x;
	int		y;

	raydir(v, d);
	x = move * v->rayx;
	y = move * v->rayy;
	v->map->posy = (int)((v->play_y - y) / v->tile_h);
	v->map->posx = (int)((v->play_x + x) / v->tile_w);
	if (v->map->map[v->map->posy][v->map->posx] != '1')
	{
		ft_view(v, 0, 0x000000, 'c');
		v->play_x += x;
		v->play_y -= y;
		my_mlx_pixel_put(v, v->play_x, v->play_y, color);
		ft_view(v, 0, 0xFFE4E1, ' ');
	}
}
