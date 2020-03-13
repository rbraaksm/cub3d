/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 17:56:13 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	player(t_vars *v, float move, unsigned int color)
{
	float		x;
	float		y;

	if (MOVE_LEFT == 1 || MOVE_RIGHT == 1)
	{
		x = move * cos(PLAYDIR);
		y = move * sin(PLAYDIR);
	}
	else
	{
		x = -(move * sin(PLAYDIR));
		y = move * cos(PLAYDIR);
	}
	if (v->MAP[(int)(PLAYER_Y - y)][(int)(PLAYER_X + x)] != '1' &&
		v->MAP[(int)(PLAYER_Y - y)][(int)(PLAYER_X + x)] != '2')
	{
		ft_view(v, 0, 0x000000);
		PLAYER_X += x;
		PLAYER_Y -= y;
		my_mlx_pixel_put(v, PLAYER_X * TILE_W, PLAYER_Y * TILE_H, color);
		ft_view(v, 0, 0x87CEFA);
	}
}
