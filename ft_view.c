/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 15:36:25 by rbraaksm      ########   odam.nl         */
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

// static void	raydir(t_vars *v)
// {
// 		v->rayx = sin(v->angle);
// 		v->rayy = cos(v->angle);
// }

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
	// raydir(v);
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
	// ft_find_sidedelta(v);
	ft_find_sidedelta(v);
}