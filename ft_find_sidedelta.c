/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 17:51:56 by rbraaksm      ########   odam.nl         */
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
			Y_HIT_ANGLE -= 0.001;
			Y_HIT -= 0.001;
			X_HIT -= X_ANGLE_INCR;
			X_HIT_ANGLE -= X_INCR;
		}
	}
	else
	{
		while (X_HIT < X_HIT_ANGLE)
		{
			Y_HIT_ANGLE -= 0.001;
			Y_HIT -= 0.001;
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
			X_HIT_ANGLE += 0.001;
			X_HIT += 0.001;
			Y_HIT += Y_ANGLE_INCR;
			Y_HIT_ANGLE += Y_INCR;
		}
	}
	else
	{
		while (Y_HIT < Y_HIT_ANGLE)
		{
			X_HIT_ANGLE += 0.001;
			X_HIT += 0.001;
			Y_HIT += Y_ANGLE_INCR;
			Y_HIT_ANGLE += Y_INCR;
		}
	}
	START = MIDDLE_Y - (fabs(Y_ANGLE) / 2);
	v->s->active_angle = Y_ANGLE;
}

void	sprite_south(t_vars *v)
{
	if (X_ANGLE_INCR > 0)
	{
		while (X_HIT < X_HIT_ANGLE)
		{
			Y_HIT_ANGLE += 0.001;
			Y_HIT += 0.001;
			X_HIT += X_ANGLE_INCR;
			X_HIT_ANGLE += X_INCR;
		}
	}
	else
	{
		while (X_HIT > X_HIT_ANGLE)
		{
			Y_HIT_ANGLE += 0.001;
			Y_HIT += 0.001;
			X_HIT += X_ANGLE_INCR;
			X_HIT_ANGLE += X_INCR;
		}
	}
	START = MIDDLE_X - (fabs(X_ANGLE) / 2);
	v->s->active_angle = X_ANGLE;
}

void	sprite_west(t_vars *v)
{
	if (X_ANGLE_INCR < 0)
	{
		while (Y_HIT < Y_HIT_ANGLE)
		{
			X_HIT_ANGLE -= 0.001;
			X_HIT -= 0.001;
			Y_HIT -= Y_ANGLE_INCR;
			Y_HIT_ANGLE -= Y_INCR;
		}
	}
	else
	{
		while (Y_HIT > Y_HIT_ANGLE)
		{
			X_HIT_ANGLE -= 0.001;
			X_HIT -= 0.001;
			Y_HIT -= Y_ANGLE_INCR;
			Y_HIT_ANGLE -= Y_INCR;
		}
	}
	START = MIDDLE_Y - (fabs(Y_ANGLE) / 2);
	v->s->active_angle = Y_ANGLE;
}

float	calc_angle(t_vars *v)
{
	if (SIDEY < SIDEX)
	{
		if ((PLAYDIR < M_PI && PLAYDIR > (M_PI * 0.5)) ||
			(PLAYDIR < (M_PI * 2) && PLAYDIR > (M_PI * 1.5)))
			return (PLAYDIR - (M_PI / 2));
		else
			return (PLAYDIR + (M_PI / 2));
	}
	else
	{
		if ((PLAYDIR < M_PI && PLAYDIR > (M_PI * 0.5)) ||
			(PLAYDIR < (M_PI * 2) && PLAYDIR > (M_PI * 1.5)))
			return (PLAYDIR + (M_PI / 2));
		else
			return (PLAYDIR - (M_PI / 2));
	}
}

int		sprite_data(t_vars *v, int side, int mapy, int mapx)
{
	if (side == 0)
	{
		WALLDIST = cos(RAY_ANGLE - PLAYDIR) * SIDEX;
		if (RAYX >= 0)
			SPRITE_HIT = 1;
		else
			SPRITE_HIT = 3;
		RAY_FINAL = SIDEX;
	}
	else
	{
		WALLDIST = cos(RAY_ANGLE - PLAYDIR) * SIDEY;
		if (RAYY > 0)
			SPRITE_HIT = 2;
		else
			SPRITE_HIT = 0;
		RAY_FINAL = SIDEY;
	}

    /* middelpunt tile */
	MIDDLE_X = (float)mapx + 0.5;
	MIDDLE_Y = (float)mapy + 0.5;
	// if (v->z < 1)
	// 	my_mlx_pixel_put(v, MIDDLE_X * TILE_W, MIDDLE_Y * TILE_H, 0xff0000);

	/* X- Y-as hits */
	X_HIT = PLAYER_X + (RAY_FINAL * RAYX);
	Y_HIT = PLAYER_Y + (RAY_FINAL * RAYY);
	// if (v->z < 1)
	// 	my_mlx_pixel_put(v, X_HIT * TILE_W, Y_HIT * TILE_H, 0xff0000);

	/* Haakse lijn op playdir */
	float	x;
	float	y;
	x = MIDDLE_X * TILE_W;
	y = MIDDLE_Y * TILE_H;
	SPRITE_ANGLE = calc_angle(v);
	// while (my_mlx_pixel_putwall(v, x, y, 0x00ff00) == 1 && v->z < 1)
	// {
	// 	x += sin(SPRITE_ANGLE);
	// 	y += cos(SPRITE_ANGLE);
	// }
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
	// if (v->z < 1 && fabs(X_HIT_ANGLE * TILE_W) > 0 && fabs(X_HIT_ANGLE * TILE_W) < v->d->resx && fabs(Y_HIT_ANGLE * TILE_H) > 0 && fabs(Y_HIT_ANGLE * TILE_H) < v->d->resy)
	// 	my_mlx_pixel_put(v, fabs(X_HIT_ANGLE * TILE_W), fabs(Y_HIT_ANGLE * TILE_H), 0xff0000);
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
	// my_mlx_pixel_put(v, fabs(X_HIT * TILE_W), fabs(Y_HIT * TILE_H), 0xff0000);
	if (X_HIT < START || X_HIT > (START + fabs(X_ANGLE)))
	{
		HAS_SPRITE = 0;
		SPRITE_FINAL = 0;
	}
	if (Y_HIT < START || Y_HIT > (START + fabs(Y_ANGLE)))
	{
		HAS_SPRITE = 0;
		SPRITE_FINAL = 0;
	}
	if (SPRITE_HIT == 0 || SPRITE_HIT == 2)
	{
		PERC = (X_HIT - START) / fabs(v->s->active_angle);
		SPRITE_FINAL = fabs(sqrt(pow(MIDDLE_X - PLAYER_X, 2) + pow(MIDDLE_Y - PLAYER_Y, 2)));	
	}
	else
	{
		PERC = 1 - ((Y_HIT - START) / fabs(v->s->active_angle));
		SPRITE_FINAL = fabs(sqrt(pow(MIDDLE_Y - PLAYER_Y, 2) + pow(MIDDLE_X - PLAYER_X, 2)));	
	}
	if (PERC > 1 || PERC < 0)
		return (0);
	HAS_SPRITE = 1;
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
	if (v->MAP[mapy][mapx] == '1')
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
