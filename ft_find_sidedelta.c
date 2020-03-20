/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/20 17:30:33 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

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
	v->s->active_angle = X_ANGLE;
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
}

int		sprite_data(t_vars *v, int side, int mapy, int mapx)
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
	MIDDLE_X = (float)mapx + 0.5;
	MIDDLE_Y = (float)mapy + 0.5;
	X_HIT = PLAYER_X + (RAY_FINAL * RAYX);
	Y_HIT = PLAYER_Y + (RAY_FINAL * RAYY);
	if (SPRITE_HIT == 1 || SPRITE_HIT == 3)
		SPRITE_ANGLE = PLAYDIR + (M_PI / 2);
	else
		SPRITE_ANGLE = PLAYDIR - (M_PI / 2);
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
	if (X_HIT < START || X_HIT > (START + fabs(X_ANGLE)))
	{
		HAS_SPRITE = 0;
		SPRITE_FINAL = 0;
	}
	else if (Y_HIT < START || Y_HIT > (START + fabs(Y_ANGLE)))
	{
		HAS_SPRITE = 0;
		SPRITE_FINAL = 0;
	}
	if (SPRITE_HIT == 0)
	{
		PERC = (X_HIT - START) / fabs(X_ANGLE);
		SPRITE_FINAL = fabs(sqrt(pow(MIDDLE_X - PLAYER_X, 2) + pow(MIDDLE_Y - PLAYER_Y, 2)));
		// if (PERC[SPRITE_I] > 1 || PERC[SPRITE_I] < 0)
		// 	return (0);
		// SPRITE_I++;
	}
	else if (SPRITE_HIT == 2)
	{
		PERC = 1 - ((X_HIT - START) / fabs(X_ANGLE));
		SPRITE_FINAL = fabs(sqrt(pow(MIDDLE_X - PLAYER_X, 2) + pow(MIDDLE_Y - PLAYER_Y, 2)));
		// if (PERC[SPRITE_I] > 1 || PERC[SPRITE_I] < 0)
		// 	return (0);
		// SPRITE_I++;
	}
	else if (SPRITE_HIT == 1)
	{
		PERC = ((Y_HIT - START) / fabs(Y_ANGLE));
		SPRITE_FINAL = fabs(sqrt(pow(MIDDLE_Y - PLAYER_Y, 2) + pow(MIDDLE_X - PLAYER_X, 2)));
		// if (PERC[SPRITE_I] > 1 || PERC[SPRITE_I] < 0)
		// 	return (0);
		// SPRITE_I++;
	}
	else if (SPRITE_HIT == 3)
	{
		PERC = 1 - ((Y_HIT - START) / fabs(Y_ANGLE));
		SPRITE_FINAL = fabs(sqrt(pow(MIDDLE_Y - PLAYER_Y, 2) + pow(MIDDLE_X - PLAYER_X, 2)));
		// if (PERC[SPRITE_I] > 1 || PERC[SPRITE_I] < 0)
		// 	return (0);
		// SPRITE_I++;
	}

	if (PERC > 1 || PERC< 0)
	{
			// SPRITE_I--;
			return (0);
	}
	HAS_SPRITE = 1;
	SPRITE_I++;
	return (1);
}

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
		if (RAYY >= 0)
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

static void	check_dir(t_vars *v)
{
	if (v->ray->playdir < 0)
		v->ray->playdir += (2 * M_PI);
	if (v->ray->playdir > (2 * M_PI))
		v->ray->playdir -= (2 * M_PI);
}

void	find_side_delta(t_vars *v)
{
	float	x;
	float	y;

	check_dir(v);
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
