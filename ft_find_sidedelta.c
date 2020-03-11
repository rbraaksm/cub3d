/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/11 16:43:16 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

float	calc_angle(t_vars *v)
{
	/* NORTH and SOUTH */
	if (v->ray->sidey < v->ray->sidex)
	{
		if ((v->ray->playdir < M_PI && v->ray->playdir > (M_PI * 0.5)) ||
			(v->ray->playdir < (M_PI * 2) && v->ray->playdir > (M_PI * 1.5)))
			return (v->ray->playdir - (M_PI / 2));
		else
			return (v->ray->playdir + (M_PI / 2));
	}
	/* EAST and WEST */
    else
	{
		if ((v->ray->playdir < M_PI && v->ray->playdir > (M_PI * 0.5)) ||
			(v->ray->playdir < (M_PI * 2) && v->ray->playdir > (M_PI * 1.5)))
			return (v->ray->playdir + (M_PI / 2));
		else
			return (v->ray->playdir - (M_PI / 2));
	}
}

int		sprite_distance(t_vars *v, int side, int mapy, int mapx)
{
	if (side == 0)
	{
		v->ray->walldist = cos(v->ray->angle - v->ray->playdir) * v->ray->sidex;
        if (v->ray->rayx >= 0)
            v->ray->side_hit = 1;
        else
            v->ray->side_hit = 3;
        v->ray->finaldist = v->ray->sidex;
    }
    else
    {
        v->ray->walldist = cos(v->ray->angle - v->ray->playdir) * v->ray->sidey;
        if (v->ray->rayy > 0)
            v->ray->side_hit = 2;
        else
            v->ray->side_hit = 0;
        v->ray->finaldist = v->ray->sidey;
    }

    /* middelpunt tile */
    v->s->middle_x = (float)mapx + 0.5;
    v->s->middle_y = (float)mapy + 0.5;
    if (v->z < 1)
        my_mlx_pixel_put(v, v->s->middle_x * v->tile_w, v->s->middle_y * v->tile_h, 0xff0000);

    /* X- Y-as hits */
    v->s->x_hit = v->player->x + (v->ray->finaldist * v->ray->rayx);
    v->s->y_hit = v->player->y + (v->ray->finaldist * v->ray->rayy);
    if (v->z < 1)
        my_mlx_pixel_put(v, v->s->x_hit * v->tile_w, v->s->y_hit * v->tile_h, 0xff0000);

    /* Haakse lijn op playdir */
    // float	angle;
    float	x;
    float	y;
    x = v->s->middle_x * v->tile_w;
    y = v->s->middle_y * v->tile_h;
	v->s->angle = calc_angle(v);
    while (my_mlx_pixel_putwall(v, x, y, 0x00ff00) == 1 && v->z < 1)
    {
        x += sin(v->s->angle);
        y += cos(v->s->angle);
    }

	float	x_hit_angle;
	float	y_hit_angle;

	v->s->x_angle = sin(v->s->angle);
	v->s->y_angle = cos(v->s->angle);
	if (v->ray->sidey < v->ray->sidex)
	{
		v->s->schuin = 0.5 / cos(v->s->angle);
		y_hit_angle = v->s->y_hit;
		if (v->ray->playdir > (M_PI * 0.75) && v->ray->playdir < (M_PI * 1.25))
			x_hit_angle = v->s->middle_x + (v->s->schuin * v->s->x_angle);
		else
			x_hit_angle = v->s->middle_x - (v->s->schuin * v->s->x_angle);
	}
	/* EAST and WEST */
    else
	{
		v->s->schuin = 0.5 / sin(v->s->angle);
		x_hit_angle = v->s->x_hit;
		if (v->ray->playdir > (M_PI * 0.25) && v->ray->playdir < (M_PI * 0.75))
			y_hit_angle = v->s->middle_y - (v->s->schuin * v->s->y_angle);
		else
			y_hit_angle = v->s->middle_y + (v->s->schuin * v->s->y_angle);
	}
	if (v->z < 1)
        my_mlx_pixel_put(v, fabs(x_hit_angle * v->tile_w), fabs(y_hit_angle * v->tile_h), 0xff0000);


    // printf("------------------\n");
    // printf("------------------\n\n");

    return (1);
}

int		wall_distance(t_vars *v, int side)
{
	if (side == 0)
	{
		v->ray->walldist = cos(v->ray->angle - v->ray->playdir) * v->ray->sidex;
		if (v->ray->rayx >= 0)
			v->ray->side_hit = 1;
		else
			v->ray->side_hit = 3;
		v->ray->finaldist = v->ray->sidex;
	}
	else
	{
		v->ray->walldist = cos(v->ray->angle - v->ray->playdir) * v->ray->sidey;
		if (v->ray->rayy > 0)
			v->ray->side_hit = 2;
		else
			v->ray->side_hit = 0;
		v->ray->finaldist = v->ray->sidey;
	}
	draw_wall(v);
	return (1);
}

int		new_sidedist(t_vars *v, int side, int mapy, int mapx)
{
	if (v->map->map[mapy][mapx] == '1' || v->map->map[mapy][mapx] == '2')
		return (wall_distance(v, side) == 1);
	if (v->map->map[mapy][mapx] == '1')
		return (wall_distance(v, side) == 1);
	if (v->map->map[mapy][mapx] == '2')
		return (sprite_distance(v, side, mapy, mapx) == 1);
	if (side == 0)
		v->ray->sidex += v->ray->deltax;
	else
		v->ray->sidey += v->ray->deltay;
	return (0);
}

void	find_hit(t_vars *v)
{
	int		side;
	int		mapx;
	int		mapy;

	mapx = v->player->x;
	mapy = v->player->y;
	while (1)
	{
		if (v->ray->sidex < v->ray->sidey)
		{
			side = 0;
			mapx += v->stepx;
		}
		else
		{
			mapy += v->stepy;
			side = 1;
		}
		if (new_sidedist(v, side, mapy, mapx) == 1)
			break ;
	}
}

void	calc_side_delta(t_vars *v, float x, float y)
{
	v->ray->rayx = sin(v->ray->playdir);
	v->ray->rayy = cos(v->ray->playdir);
	v->ray->sidex = fabs(x / v->ray->rayx);
	v->ray->sidey = fabs(y / v->ray->rayy);
	v->ray->deltax = fabs(1 / v->ray->rayx);
	v->ray->deltay = fabs(1/ v->ray->rayy);
}

void	ft_find_sidedelta(t_vars *v)
{
	float	x;
	float	y;

	v->ray->sprite = 0;
	if (v->ray->playdir > (0.5 * M_PI) && v->ray->playdir < (1.5 * M_PI))
		y = v->player->y - (int)v->player->y;
	else
		y = 1 - (v->player->y - (int)v->player->y);
	if (v->ray->playdir > M_PI && v->ray->playdir < (M_PI * 2))
		x = v->player->x - (int)v->player->x;
	else
		x = 1 - (v->player->x - (int)v->player->x);
	calc_side_delta(v, x, y);
	if (v->ray->rayx < 0)
		v->stepx = -1;
	else
		v->stepx = 1;
	if (v->ray->rayy < 0)
		v->stepy = -1;
	else
		v->stepy = 1;
	find_hit(v);
}