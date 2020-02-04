/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map2d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:13:44 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/04 11:38:06 by rbraaksm      ########   odam.nl         */
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

void	player(t_vars *vars, char c, int move, unsigned int color)
{
	int	ys;
	int	ye;
	int	xs;
	int	xe;

	ft_view(vars, 0, 0x000000);
	vars->player = color;
	if (c == 'x')
		vars->play_x += move;
	if (c == 'y')
		vars->play_y += move;
	ys = vars->play_y - (vars->hor /2) + 3;
	if (ys < 0)
		ys = 0;
	ye = ys + vars->hor - 6;
	if (ye > vars->data->resy)
	{
		ye = vars->data->resy;
		ys = vars->data->resy - vars->hor + 6;
	}
	xs = vars->play_x - (vars->ver / 2) + 3;
	if (xs < 0)
	{
		xs = 0;
		xe = xs + vars->ver - 6;
	}
	xe = xs + vars->ver - 6;
	if (xe > vars->data->resx)
	{
		xe = vars->data->resx;
		xs = xe - vars->data->resx;
	}
	while (ys < ye)
	{
		xs = vars->play_x - (vars->ver / 2) + 3;
		if (xs < 0)
			xs = 0;
		while (xs < xe)
		{
			my_mlx_pixel_put(vars, vars->play_x, vars->play_y, vars->player);
			xs++;
		}
		ys++;
	}
	ft_view(vars, 0, 0xffff00);
}

void	printblock(t_vars *vars, int row, int column)
{
	int				x;
	int				y;
	
	y = row * vars->hor;
	while (y < ((row * vars->hor) + vars->hor))
	{
		x = column * vars->ver;
		while (x < ((column * vars->ver) + vars->ver))
		{
			if (vars->map->map[row][column] == '1')
				my_mlx_pixel_put(vars, x, y, 0x8A2BE2);
			// else if (vars->map->map[row][column] == '2')
			// 	my_mlx_pixel_put(vars, x, y, 0x00FF7F);
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
				vars->play_y = r * vars->hor + (vars->hor / 2);
				vars->play_x = c * vars->ver + (vars->ver / 2);
			}
			c++;
		}
		r++;
	}
}

void	ft_make_2d(t_vars *vars)
{
	make_grid(vars);
	player(vars, ' ', 0, 0x00BFFF);
	ft_view(vars, 0, 0xffff00);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
}