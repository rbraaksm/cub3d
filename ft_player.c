/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/04/01 11:34:22 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

static int	check_step(t_vars *v, float x, float y)
{
	if (v->MAP[(int)(PLAYER_Y - y)][(int)(PLAYER_X)] == '1')
		return (1);
	if (v->MAP[(int)(PLAYER_Y - y)][(int)(PLAYER_X + x)] == '1')
		return (1);
	return (0);
}

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
	color = 0xff0000;
	if (check_step(v, x, y) == 0)
	{
		ft_view(v, 0, 0x000000);
		PLAYER_X += x;
		PLAYER_Y -= y;
		ft_view(v, 0, 0x87CEFA);
	}
}
