/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/03 17:34:16 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		keycode(int keycode, t_vars *vars)
{
	if (keycode == 53)
    	mlx_destroy_window(vars->mlx, vars->win);
	if (keycode == 126)
	{
		player(vars, ' ', 0, 0x000000);
		player(vars, 'y', -5, 0x00BFFF);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 123)
	{
		player(vars, ' ', 0, 0x000000);
		player(vars, 'x', -5, 0x00BFFF);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 124)
	{
		player(vars, ' ', 0, 0x000000);
		player(vars, 'x', 5, 0x00BFFF);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 125)
	{
		player(vars, ' ', 0, 0x000000);
		player(vars, 'y', 5, 0x00BFFF);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 2)
	{
		ft_view(vars, 10);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	return (keycode);
}

void	get_info(t_vars *vars)
{
	vars->ver = vars->data->resx / vars->map->column;
	vars->hor = vars->data->resy / vars->map->row;

}

void	window(t_flags *data, t_color *color, t_map *map)
{
	t_vars	vars;

	vars.map = map;
	vars.data = data;
	vars.color = color;
	get_info(&vars);

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->resx, data->resy, "CUB3D");

	// 	/*close window */
	mlx_hook(vars.win, 2, 1L<<0, keycode, &vars);
	
	vars.mapimg = mlx_new_image(vars.mlx, data->resx, data->resy);
	vars.addr = mlx_get_data_addr(vars.mapimg, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

	/* make 2D map */
	ft_make_2d(&vars);

	/* make ray / find wall */
	// ft_findwall(&vars);
	mlx_loop(vars.mlx);
}