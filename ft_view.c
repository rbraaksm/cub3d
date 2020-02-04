/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/04 12:34:36 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	ft_view(t_vars *vars, double rot, unsigned int color)
{
	double	x;
	double	y;
	double	x1;
	double	y1;

	vars->angle += rot;
	x = vars->play_x;
	y = vars->play_y;
	x1 = sin(vars->angle);
	y1 = cos(vars->angle);

	while (x > 0 && x < vars->data->resx && y > 0 && y < vars->data->resy)
	{
		my_mlx_pixel_put(vars, x, y, color);
		x += x1;
		y += y1;

	}
}
