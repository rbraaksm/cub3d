/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/05 14:07:53 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	ft_find_intersection(t_vars *vars)
{
	double	hoek = vars->angle * 180 / M_PI;
	if (hoek < 0)
		hoek += 360;
	if (hoek > 360)
		hoek -= 360;
	// double	dx;
	// double	y;

	// y = ((int)vars->play_y / (int)vars->hor) * vars->hor;
	// x = vars->play_x + sin(vars->angle * 180);
	// dx = (vars->map->posx * vars->ver) + (vars->play_x / vars->ver);

	// printf("[hoek] %f\n", hoek);
	// printf("[x] %f\n", x);
	// printf("[y] %f\n", y);
	// printf("[angle] %f\n", vars->angle);
	// printf("[tan] %f\n", tan(vars->angle));
	// printf("[sin] %f\n", sin(vars->angle));
	// printf("[cos] %f\n", cos(vars->angle));
	// printf("[posx] %d\n", vars->map->posx);
	// printf("[ix] %f\n", ix);
	// printf("[iy] %f\n", iy);
	// my_mlx_pixel_put(vars, x, y, 0xffff00);


}

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
	// printf("[Play x] %d\n", vars->play_x);
	// printf("[Play y] %d\n", vars->play_y);

	ft_find_intersection(vars);
}