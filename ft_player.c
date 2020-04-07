/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/07 15:10:51 by rbraaksm      ########   odam.nl         */
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

void	player(t_vars *v, float move)
{
	float		x;
	float		y;

	x = 0;
	y = 0;
	if (MOVE_LEFT == 1 || MOVE_RIGHT == 1)
	{
		x = move * cos(PLAYDIR);
		y = move * sin(PLAYDIR);
	}
	else if (MOVE_FORWARD == 1 || MOVE_BACKWARDS)
	{
		x = -(move * sin(PLAYDIR));
		y = move * cos(PLAYDIR);
	}
	if (check_step(v, x, y) == 0)
	{
		PLAYER_X += x;
		PLAYER_Y -= y;
		ft_view(v, 0);
	}
}
