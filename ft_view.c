/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/03 18:12:01 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	ft_view(t_vars *vars, int rot)
{
	float	x0;
	float	y0;
	float	x1;
	float	x2;

	vars->pi =  3.1415926535;
	vars->angle = 30 * (vars->pi / 180);


	x0 = vars->play_x;
	y0 = vars->play_y - 50;
	x1 = 50 * (30 * (vars->pi / 180)) + vars->play_x;
	x2 = vars->play_x - (50 * (30 * (vars->pi / 180)));

	my_mlx_pixel_put(vars, x0, y0, 0xffff00);
	my_mlx_pixel_put(vars, x1, y0, 0xffff00);
	my_mlx_pixel_put(vars, x2, y0, 0xffff00);

	printf("[x0] %f\n", x0);
	printf("[x1] %f\n", x1);
	printf("[x2] %f\n", x2);

	rot = 0;
}