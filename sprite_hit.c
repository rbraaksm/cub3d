/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_hit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:56:50 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:13:33 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_north(t_vars *v)
{
	if (X_ANGLE_INCR > 0)
	{
		while (X_HIT > X_HIT_ANGLE)
		{
			X_HIT -= X_ANGLE_INCR;
			X_HIT_ANGLE -= X_INCR;
		}
	}
	else
	{
		while (X_HIT < X_HIT_ANGLE)
		{
			X_HIT -= X_ANGLE_INCR;
			X_HIT_ANGLE -= X_INCR;
		}
	}
	START = MIDDLE_X - (fabs(X_ANGLE) / 2);
	PERC[SPRITE_I] = (X_HIT - START) / fabs(X_ANGLE);
	SPRITE_FINAL[SPRITE_I] = fabs(sqrt(pow(MIDDLE_X - PLAYER_X, 2) +
	pow(MIDDLE_Y - PLAYER_Y, 2)));
}

void	sprite_east(t_vars *v)
{
	if (X_ANGLE_INCR < 0)
	{
		while (Y_HIT > Y_HIT_ANGLE)
		{
			Y_HIT += Y_ANGLE_INCR;
			Y_HIT_ANGLE += Y_INCR;
		}
	}
	else
	{
		while (Y_HIT < Y_HIT_ANGLE)
		{
			Y_HIT += Y_ANGLE_INCR;
			Y_HIT_ANGLE += Y_INCR;
		}
	}
	START = MIDDLE_Y - (fabs(Y_ANGLE) / 2);
	PERC[SPRITE_I] = ((Y_HIT - START) / fabs(Y_ANGLE));
	SPRITE_FINAL[SPRITE_I] = fabs(sqrt(pow(MIDDLE_Y - PLAYER_Y, 2) +
	pow(MIDDLE_X - PLAYER_X, 2)));
}

void	sprite_south(t_vars *v)
{
	if (X_ANGLE_INCR > 0)
	{
		while (X_HIT < X_HIT_ANGLE)
		{
			X_HIT += X_ANGLE_INCR;
			X_HIT_ANGLE += X_INCR;
		}
	}
	else
	{
		while (X_HIT > X_HIT_ANGLE)
		{
			X_HIT += X_ANGLE_INCR;
			X_HIT_ANGLE += X_INCR;
		}
	}
	START = MIDDLE_X - (fabs(X_ANGLE) / 2);
	PERC[SPRITE_I] = 1 - ((X_HIT - START) / fabs(X_ANGLE));
	SPRITE_FINAL[SPRITE_I] = fabs(sqrt(pow(MIDDLE_X - PLAYER_X, 2) +
	pow(MIDDLE_Y - PLAYER_Y, 2)));
}

void	sprite_west(t_vars *v)
{
	if (X_ANGLE_INCR < 0)
	{
		while (Y_HIT < Y_HIT_ANGLE)
		{
			Y_HIT -= Y_ANGLE_INCR;
			Y_HIT_ANGLE -= Y_INCR;
		}
	}
	else
	{
		while (Y_HIT > Y_HIT_ANGLE)
		{
			Y_HIT -= Y_ANGLE_INCR;
			Y_HIT_ANGLE -= Y_INCR;
		}
	}
	START = MIDDLE_Y - (fabs(Y_ANGLE) / 2);
	PERC[SPRITE_I] = 1 - ((Y_HIT - START) / fabs(Y_ANGLE));
	SPRITE_FINAL[SPRITE_I] = fabs(sqrt(pow(MIDDLE_Y - PLAYER_Y, 2) +
	pow(MIDDLE_X - PLAYER_X, 2)));
}
