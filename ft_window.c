/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/29 18:06:35 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	printstart(t_vars *vars, int hor, int ver, int row, int column)
{
	int				x;
	int				y;
	
	y = row * hor;
	while (y < ((row * hor) + hor))
	{
		x = column * ver;
		while (x < ((column * ver) + ver))
		{
			my_mlx_pixel_put(vars, x, y, 0xffff00);
			x++;
		}
		y++;
	}
}

void	printblock(t_vars *vars, int hor, int ver, int row, int column)
{
	int				x;
	int				y;
	
	y = row * hor;
	while (y < ((row * hor) + hor))
	{
		x = column * ver;
		while (x < ((column * ver) + ver))
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
	int		hor;	
	int		ver;

	ver = vars->data->resx / vars->map->column;
	hor = vars->data->resy / vars->map->row;
	r = 0;
	while (r < vars->map->row)
	{
		c = 0;
		while (c < vars->map->column)
		{
			if (vars->map->map[r][c] == '1' || vars->map->map[r][c] == '2')
				printblock(vars, hor, ver, r, c);
			else if (vars->map->map[r][c] == 'S')
				printstart(vars, hor, ver, r, c);
			c++;
		}
		r++;
	}
}

int		keycode(int keycode, t_vars *vars)
{
	if (keycode == 53)
    	mlx_destroy_window(vars->mlx, vars->win);
	if (keycode == 49)
	{
		make_grid(vars);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	return (keycode);
}

void	window(t_flags *data, t_color *color, t_map *map)
{
	t_vars	vars;


	vars.map = map;
	vars.data = data;
	vars.color = color;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->resx, data->resy, "CUB3D");
	vars.mapimg = mlx_new_image(vars.mlx, data->resx, data->resy);
	vars.img = mlx_new_image(vars.mlx, data->resx, data->resy);
	vars.addr = mlx_get_data_addr(vars.mapimg, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

	// 	/*close window */
	mlx_hook(vars.win, 2, 1L<<0, keycode, &vars);

	mlx_loop(vars.mlx);
}