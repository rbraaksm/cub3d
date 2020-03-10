/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_sidedelta.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:40:17 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/10 13:59:41 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"


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
	float	middle_x;
	float	middle_y;
	middle_x = (float)mapx + 0.5;
	middle_y = (float)mapy + 0.5;
	// my_mlx_pixel_put(v, middle_x * v->tile_h, middle_y * v->tile_w, 0xff0000);

	/* X- Y-as hits */
	float	x_hit;
	float	y_hit;
	x_hit = v->player->x + (v->ray->finaldist * v->ray->rayx);
	y_hit = v->player->y + (v->ray->finaldist * v->ray->rayy);
	// my_mlx_pixel_put(v, x_hit * v->tile_w, y_hit * v->tile_h, 0xff0000);

	float	angle;
	float	haaks;
	float	angle_x;
	float	angle_y;
	float	bottom_x;
	float	bottom_y;
	float	new_x_hit;
	float	new_bottom_x;
	int		i;
	float	bottom_x_incr;
	float	hit_x_incr;
	
	angle = v->ray->playdir + (M_PI / 2);
	haaks = 0.5 / cos(angle);
	angle_x = sin(angle);
	angle_y = cos(angle);
	bottom_x = middle_x + (haaks * angle_x);
	bottom_y = y_hit;

	// printf("----------------\n");
	// printf("angle: %f\n", angle);
	// printf("haaks: %f\n", haaks);
	// printf("angle_x: %f\n", angle_x);
	// printf("angle_y: %f\n", angle_y);
	// printf("bottom_x: %f\n", bottom_x);
	// printf("bottom_y: %f\n", bottom_y);
	// printf("----------------\n\n");
	// my_mlx_pixel_put(v, (int)(bottom_x * v->tile_w), (int)(bottom_y * v->tile_h), 0xFF0000);

	new_x_hit = x_hit;
	new_bottom_x = bottom_x;
	i = 0;

	hit_x_incr = fabs((v->ray->rayx / v->ray->rayy) * 0.01);
	bottom_x_incr = fabs((angle_x / angle_y) * 0.01);

	// while (1)
	// {
	// 	bottom_y -= 0.01;
    //     y_hit -= 0.01;
    //     x_hit -= hit_x_incr;
    //     bottom_x += bottom_x_incr;
    //     // my_mlx_pixel_put(v, (bottom_x * v->tile_w), (bottom_y * v->tile_h), 0xFFF00F);
    //     if (x_hit < bottom_x)
    //     {
    //         printf("found\n");
    //         // printf("x: %f y: %f\n", bottom_x, bottom_y);
    //         break;
    //     }
        
    //     i++;
    // }
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
	return (1);
}

int		new_sidedist(t_vars *v, int side, int mapy, int mapx)
{
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
	// if (v->map->map[mapy][mapx] == '1')
	// 	wall_distance(v, side);
	// if (v->map->map[mapy][mapx] == '2')
	// 	sprite_distance(v, side);
}

void	calc_side_delta(t_vars *v, float x, float y)
{
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