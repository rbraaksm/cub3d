/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/10 15:16:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		my_mlx_pixel_putwall(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (vars->map->map[y / (int)vars->tile_h][x / (int)vars->tile_w] == '1' ||
		vars->map->map[y / (int)vars->tile_h][x / (int)vars->tile_w] == '2')
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
	// printf("[angle]  %f\n", vars->angle);
	double x = 0.0;
	double y = 0.0;
	// double disty = 0.0;


	if (vars->angle < (1.5 * M_PI) && vars->angle > (0.5 * M_PI))
	{
		x = (int)vars->play_x % (int)vars->tile_w;
		y = fabs(x / tan(vars->angle));
		my_mlx_pixel_put(vars, vars->play_x + x, vars->play_y - y, 0xff0000);
		printf("[x]      %f\n", x);
		printf("[play_y] %f\n", vars->play_y);
		printf("[y]      %f\n", y);
	}

	


}

void	ft_view(t_vars *vars, double rot, unsigned int color, char c)
{
	double	x;
	double	y;
	double	tmp;
	int		i;

	if (vars->angle < 0)
		vars->angle += (2 * M_PI);
	if (vars->angle > (2 * M_PI))
		vars->angle -= (2 * M_PI);
	if (c == 'c')
		ft_view(vars, 0, 0x000000, ' ');
	vars->angle += rot;
	tmp = vars->angle;
	// vars->angle -= 0.25;
	// while (vars->angle > (tmp - 0.26) && vars->angle < (tmp + 0.26))
	// {
		i = 0;
		x = vars->play_x;
		y = vars->play_y;
		while (my_mlx_pixel_putwall(vars, x, y, color) == 1 && i < 60)
		{
			x += sin(vars->angle);
			y += cos(vars->angle);
			// i++;
		}
	// 	vars->angle += 0.001;
	// }
	// vars->angle = tmp;
	ft_find_intersection(vars);
}