/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/17 14:41:34 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		my_mlx_pixel_putwall(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (v->map->map[y / (int)v->tile_h][x / (int)v->tile_w] == '1' ||
		v->map->map[y / (int)v->tile_h][x / (int)v->tile_w] == '2')
		return (0);
	else
	{
		dst = v->addr + (y * v->line_length + x *
		(v->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		return (1);
	}
}

void	ft_find_hit(t_vars *v, int stepx, int stepy)
{
	int		hit;
	int		mapx;
	int		mapy;
	int		side;

	hit = 0;
	while (hit == 0)
	{
		mapx = v->map->posx;
		mapy = v->map->posy;
		if (v->sidex < v->sidey)
		{
			v->sidex += v->deltax;
			mapx += stepx;
			side = 0;
		}
		else
		{
			v->sidey += v->deltay;
			mapy += stepy;
			side = 1;
		}
		if (v->map->map[mapy][mapx] > 0)
			hit = 1;
	}
	printf("[hit] %d\n", hit);
	printf("[mapx] %d\n", mapx);
	printf("[mapy] %d\n", mapy);
	printf("[posx] %d\n", v->map->posx);
	printf("[posy] %d\n", v->map->posy);
	printf("[rayy] %f\n", v->rayy);
	printf("[rayx] %f\n", v->rayx);
	if (side == 0)
		v->walldist = (mapx - v->map->posx + (1 - stepx) / 2) / v->rayx;
	else
		v->walldist = (mapy - v->map->posy + (1 - stepy) / 2) / v->rayy;
}

void	ft_find_sidedelta(t_vars *v)
{
	double	x;
	double	y;
	int		stepx;
	int		stepy;

	if (v->angle > (0.5 * M_PI) && v->angle < (1.5 * M_PI))
		y = (int)v->play_y % (int)v->tile_h;
	else
		y = v->tile_h - ((int)v->play_y % (int)v->tile_h);
	if (v->angle > M_PI)
		x = (int)v->play_x % (int)v->tile_w;
	else
		x = v->tile_w - ((int)v->play_x % (int)v->tile_w);
	v->sidex = fabs(x / sin(v->angle));
	v->sidey = fabs(y / cos(v->angle));
	v->deltax = fabs(v->tile_w / sin(v->angle));
	v->deltay = fabs(v->tile_h / cos(v->angle));
	if (v->rayx < 0)
		stepx = -1;
	else
		stepx = 1;
	if (v->rayy < 0)
		stepy = 1;
	else
		stepy = -1;
	printf("[sidex] %f\n", v->sidex);
	printf("[sidey] %f\n", v->sidey);
	ft_find_hit(v, stepx, stepy);
}

void	ft_view(t_vars *v, double rot, unsigned int color, char c)
{
	double	x;
	double	y;
	double	tmp;

	if (v->angle < 0)
		v->angle += (2 * M_PI);
	if (v->angle > (2 * M_PI))
		v->angle -= (2 * M_PI);
	if (c == 'c')
		ft_view(v, 0, 0x000000, ' ');
	v->angle += rot;
	tmp = v->angle;
	// v->angle -= 0.25;
	// while (v->angle > (tmp - 0.26) && v->angle < (tmp + 0.26))
	// {
		x = v->play_x;
		y = v->play_y;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(v->angle);
			y += cos(v->angle);
		}
		// v->angle += 0.05;
	// }
	// v->angle = tmp;
	ft_find_sidedelta(v);
}