/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_data.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:37:15 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:13:28 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_values(t_vars *v, int mapx, int mapy)
{
	MIDDLE_X = (float)mapx + 0.5;
	MIDDLE_Y = (float)mapy + 0.5;
	X_HIT = PLAYER_X + (RAY_FINAL * RAYX);
	Y_HIT = PLAYER_Y + (RAY_FINAL * RAYY);
	SPRITE_ANGLE = PLAYDIR + (M_PI / 2);
	X_ANGLE = sin(SPRITE_ANGLE);
	Y_ANGLE = cos(SPRITE_ANGLE);
	if (SIDEY < SIDEX)
	{
		SCHUIN = 0.5 / cos(SPRITE_ANGLE);
		Y_HIT_ANGLE = Y_HIT;
		if (PLAYDIR > (M_PI * 0.5) && PLAYDIR < (M_PI * 1.5))
			X_HIT_ANGLE = MIDDLE_X + (SCHUIN * X_ANGLE);
		else
			X_HIT_ANGLE = MIDDLE_X - (SCHUIN * X_ANGLE);
	}
	else
	{
		SCHUIN = 0.5 / sin(SPRITE_ANGLE);
		X_HIT_ANGLE = X_HIT;
		if (PLAYDIR < M_PI && PLAYDIR > 0)
			Y_HIT_ANGLE = MIDDLE_Y - (SCHUIN * Y_ANGLE);
		else
			Y_HIT_ANGLE = MIDDLE_Y + (SCHUIN * Y_ANGLE);
	}
}

void	sprite_hit(t_vars *v, int side)
{
	if (side == 0)
	{
		if (RAYX >= 0)
			SPRITE_HIT = 1;
		else
			SPRITE_HIT = 3;
		RAY_FINAL = SIDEX;
	}
	else
	{
		if (RAYY >= 0)
			SPRITE_HIT = 2;
		else
			SPRITE_HIT = 0;
		RAY_FINAL = SIDEY;
	}
}

int		sprite_data(t_vars *v, int side, int mapy, int mapx)
{
	sprite_hit(v, side);
	sprite_values(v, mapx, mapy);
	X_INCR = (X_ANGLE / Y_ANGLE) * 0.001;
	X_ANGLE_INCR = (RAYX / RAYY) * 0.001;
	Y_INCR = (Y_ANGLE / X_ANGLE) * 0.001;
	Y_ANGLE_INCR = (RAYY / RAYX) * 0.001;
	if (SPRITE_HIT == 0)
		sprite_north(v);
	else if (SPRITE_HIT == 1)
		sprite_east(v);
	else if (SPRITE_HIT == 2)
		sprite_south(v);
	else if (SPRITE_HIT == 3)
		sprite_west(v);
	SPRITE_FINAL[SPRITE_I] *= cos(fabs(RAY_ANGLE - PLAYDIR));
	if (PERC[SPRITE_I] > 1 || PERC[SPRITE_I] < 0)
		return (0);
	HAS_SPRITE = 1;
	SPRITE_I++;
	return (1);
}
