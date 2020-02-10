/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/10 14:38:07 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	updown_player(t_vars *vars, double move, unsigned int color, char c)
{
	int		x;
	int		y;

	if (c == 'c')
		updown_player(vars, 1, 0x000000, ' ');
	x = (vars->play_x - (move * sin(vars->angle))) / vars->tile_w;
	y = (vars->play_y - (move * cos(vars->angle))) / vars->tile_h;
	if (vars->map->map[y][x] != '1')
	{
			ft_view(vars, 0, 0x000000, 'c');
			vars->play_x -= (move * sin(vars->angle));
			vars->play_y -= move * cos(vars->angle);
			my_mlx_pixel_put(vars, vars->play_x, vars->play_y, color);
			ft_view(vars, 0, 0xFFE4E1, ' ');
	}
}

void	leftright_player(t_vars *vars, double move, unsigned int color, char c)
{
	int		x;
	int		y;

	if (c == 'c')
		leftright_player(vars, 0, 0x000000, ' ');
	x = (vars->play_x + (move * cos(vars->angle))) / vars->tile_w;
	y = (vars->play_y - (move * sin(vars->angle))) / vars->tile_h;
	if (vars->map->map[y][x] != '1')
	{
			ft_view(vars, 0, 0x000000, 'c');
			vars->play_x += move * cos(vars->angle);
			vars->play_y -= move * sin(vars->angle);
			my_mlx_pixel_put(vars, vars->play_x, vars->play_y, color);
			ft_view(vars, 0, 0xFFE4E1, ' ');
	}
}