/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/13 21:06:25 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wall_data(t_vars *v, int side)
{
	if (side == 0)
	{
		WALLDIST = cos(RAY_ANGLE - PLAYDIR) * SIDEX;
		if (RAYX >= 0)
			SIDE_HIT = 1;
		else
			SIDE_HIT = 3;
		RAY_FINAL = SIDEX;
	}
	else
	{
		WALLDIST = cos(RAY_ANGLE - PLAYDIR) * SIDEY;
		if (RAYY > 0)
			SIDE_HIT = 2;
		else
			SIDE_HIT = 0;
		RAY_FINAL = SIDEY;
	}
	return (1);
}

int		new_sidedist(t_vars *v, int side, int mapy, int mapx)
{
	if (v->MAP[mapy][mapx] == '2')
		sprite_data(v, side, mapy, mapx);
	else if (v->MAP[mapy][mapx] == '1')
		return ((wall_data(v, side) == 1));
	if (side == 0)
		SIDEX += DELTAX;
	else
		SIDEY += DELTAY;
	return (0);
}

void	find_hit(t_vars *v)
{
	int		side;
	int		mapx;
	int		mapy;

	mapx = PLAYER_X;
	mapy = PLAYER_Y;
	while (1)
	{
		if (SIDEX < SIDEY)
		{
			side = 0;
			mapx += STEP_X;
		}
		else
		{
			mapy += STEP_Y;
			side = 1;
		}
		if (new_sidedist(v, side, mapy, mapx) == 1)
			break ;
	}
}

void	find_side_delta(t_vars *v)
{
	float	x;
	float	y;

	if (PLAYDIR > (0.5 * M_PI) && PLAYDIR < (1.5 * M_PI))
		y = PLAYER_Y - (int)PLAYER_Y;
	else
		y = 1 - (PLAYER_Y - (int)PLAYER_Y);
	if (PLAYDIR > M_PI && PLAYDIR < (M_PI * 2))
		x = PLAYER_X - (int)PLAYER_X;
	else
		x = 1 - (PLAYER_X - (int)PLAYER_X);
	RAYX = sin(PLAYDIR);
	RAYY = cos(PLAYDIR);
	SIDEX = fabs(x / RAYX);
	SIDEY = fabs(y / RAYY);
	DELTAX = fabs(1 / RAYX);
	DELTAY = fabs(1 / RAYY);
	if (RAYX < 0)
		STEP_X = -1;
	else
		STEP_X = 1;
	if (RAYY < 0)
		STEP_Y = -1;
	else
		STEP_Y = 1;
}
