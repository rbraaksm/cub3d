/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/30 15:26:00 by rbraaksm      ########   odam.nl         */
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
		player(vars, 0x000000);
		vars->play_y -= 5;
		player(vars, 0xffff00);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 123)
	{
		player(vars, 0x000000);
		vars->play_x -= 5;
		player(vars, 0xffff00);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 124)
	{
		player(vars, 0x000000);
		vars->play_x += 5;
		player(vars, 0xffff00);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->mapimg, 0, 0);
	}
	if (keycode == 125)
	{
		player(vars, 0x000000);
		vars->play_y += 5;
		player(vars, 0xffff00);
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
	
	double posx = map->posx;
	double posy = map->posy;
	double dirx = -1;
	double diry = 0;
	double planex = 0;
	double planey = 0.66;

	while (1)
	{
		vars.mapimg = mlx_new_image(vars.mlx, data->resx, data->resy);
		vars.addr = mlx_get_data_addr(vars.mapimg, &vars.bits_per_pixel, &vars.line_length, &vars.endian);

		/*make 2D map */
		ft_make_2d(&vars);
		int x = 0;
		while (x < data->resx)
		{
			/* Calculate ray position and direction */
			double camerax = 2 * x / ((double)data->resy -1); //x-coordinate in camera space
			double raydirx = dirx + planex * camerax;
			double raydiry = diry + planey * camerax;
			// printf("[camerax] %f\n", camerax);
			/* Which box of the map we're in */
			int mapx = (int)posx;
			int mapy = (int)posy;

			/* Length of ray from current position to next x or y-side */
			double sidedistx;
			double sidedisty;

			/* Length of ray from one x or y-side to next x or y-side */
			double deltadistx = sqrt(1 / raydirx);
			double deltadisty = sqrt(1 / raydiry);
			// double perpwalldist;

			/* What direction to step in x or y-direction (eitgher +1 or -1) */
			int stepx;
			int stepy;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit ?

			/* Calculate step and initial sidedist */
			if (raydirx < 0)
			{
				stepx = -1;
				sidedistx = (posx - mapx) * deltadistx;
			}
			else
			{
				stepx = 1;
				sidedistx = (mapx + 1.0 - posx) * deltadistx;
			}
			if (raydiry < 0)
			{
				stepy = -1;
				sidedisty = (posy - mapy) * deltadisty;
			}
			else
			{
				stepy = 1;
				sidedisty = (mapy + 1.0 - posy) * deltadisty;
			}

			/* Perform DDA */
			while (hit == 0)
			{
				/* Jump to next square, or in x-direction or y-direction */
				if (sidedistx < sidedisty)
				{
					sidedistx += deltadistx;
					mapx += stepx;
					side = 0;
				}
				else
				{
					sidedisty += deltadisty;
					mapy += stepy;
					side = 0;
				}
				/* Check is ray has hit a wall */
				printf("[mapx] %d\n", map->posx);
				printf("[mapy] %d\n", map->posy);
				if (map->map[mapx][mapy] > 0)
					hit = 1;
			}
			x++;
		}
	mlx_loop(vars.mlx);
	}

}