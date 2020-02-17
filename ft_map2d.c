/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map2d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:13:44 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/17 11:58:46 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	printblock(t_vars *vars, int row, int column)
{
	int				x;
	int				y;

	y = row * vars->tile_h;
	while (y < ((row * vars->tile_h) + vars->tile_h))
	{
		x = column * vars->tile_w;
		while (x < ((column * vars->tile_w) + vars->tile_w))
		{
			if (vars->map->map[row][column] == '1')
				my_mlx_pixel_put(vars, x, y, 0x8A2BE2);
			else if (vars->map->map[row][column] == '2')
				my_mlx_pixel_put(vars, x, y, 0x00FF7F);
			x++;
		}
		y++;
	}
}

void	make_grid(t_vars *vars)
{
	int		r;
	int		c;

	r = 0;
	while (r < vars->map->row)
	{
		c = 0;
		while (c < vars->map->column)
		{
			if (vars->map->map[r][c] == '1' || vars->map->map[r][c] == '2')
				printblock(vars, r, c);
			if (vars->map->map[r][c] == 'S')
			{
				vars->play_y = r * vars->tile_h + (vars->tile_h / 2);
				vars->play_x = c * vars->tile_w + (vars->tile_w / 2);
			}
			c++;
		}
		r++;
	}
}

void	ft_make_2d(t_vars *vars)
{
	make_grid(vars);
	player(vars, 0, 'h', 0x00BFFF);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
}
