/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/11 11:19:09 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	player(t_vars *vars, double move, char d, unsigned int color, char c)
{
	int		x;
	int		y;

	if (c == 'c')
		player(vars, 0, d, 0x000000, ' ');
	if (d == 'h')
	{
		x = move * cos(vars->angle);
		y = move * sin(vars->angle);
	}
	else
	{
		x = -(move * sin(vars->angle));
		y = move * cos(vars->angle);
	}
	if (vars->map->map[(int)((vars->play_y - y) / vars->tile_h)][(int)((vars->play_x + x) / vars->tile_w)] != '1')
	{
			ft_view(vars, 0, 0x000000, 'c');
			vars->play_x += x;
			vars->play_y -= y;
			my_mlx_pixel_put(vars, vars->play_x, vars->play_y, color);
			ft_view(vars, 0, 0xFFE4E1, ' ');
	}
}