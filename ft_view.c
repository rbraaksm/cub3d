/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/06 16:46:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int	my_mlx_pixel_putwall(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (vars->map->map[y / (int)vars->hor][x / (int)vars->ver] == '1' ||
		vars->map->map[y / (int)vars->hor][x / (int)vars->ver] == '2')
		return (0);
	else
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		return (1);
	}
}

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
	// printf("[play_x] %d\n", vars->play_x);
	// printf("[play_y] %d\n", vars->play_y);
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

void	ft_view(t_vars *vars, double rot, unsigned int color, char c)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	i = 0;
	if (c == 'c')
		ft_view(vars, 0, 0x000000, ' ');
	vars->angle += rot;
	tmp = vars->angle;
	x = vars->play_x;
	y = vars->play_y;
	vars->angle -= 0.20;
	while (vars->angle >= (tmp - 0.21) && vars->angle <= (tmp + 0.21))
	{
		while (my_mlx_pixel_putwall(vars, x, y, color) == 1)
		{
			x += sin(vars->angle);
			y += cos(vars->angle);
		}
		x = vars->play_x;
		y = vars->play_y;
		vars->angle += 0.001;
		i++;
	}
	vars->angle = tmp;
	// ft_find_intersection(vars);
}