/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/23 16:26:35 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int             ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
    	mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}

int		mouse(int x, int y, t_vars *vars)
{
	if ((x > 0 && x < 800) && (y > 0 && y < 800))
	{
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0x000000FF, "Hello");
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0xFF000000, "Bye");
		printf("x = %d\n", x);
		printf("y = %d\n", y);
	}
	if ((x < 0 && x > 800) && (y < 0 && y > 800))
	{
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0xFF000000, "Hello");
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0x000000FF, "bye");
	}
		return (1);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_flags *data)
{
	t_data	img;
	t_vars	vars;
	// int		x;
	// int		y;
	// int		a;
	// int		b;
	
		/*close window */
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->resx, data->resy, "CUB3D");
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);

	
	img.img = mlx_new_image(vars.mlx, data->resx, data->resy);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	
	/* mouse */
	mlx_hook(vars.win, 6, 1L<<6, mouse, &vars);


	// /* Vierkant */
	// y = 50;
	// while (y < 150)
	// {
	// 	x = 50;
	// 	while (x < 150)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, data->floor);
	// 		x++;
	// 	}
	// 	data->floor += 1;
	// 	y++;
	// }
	
	// /* 90 gr Driehoek */
	// y = 50;
	// x = 600;
	// a = x;
	// while (y < 200)
	// {
	// 	while (x < 600)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, data->ceiling);
	// 		x++;
	// 	}
	// 	a -= 1;
	// 	x = a;
	// 	y++;
	// 	data->ceiling -= 100;
	// }

	// /* 45 gr Diehoek */
	// int line;

	// y = 250;
	// x = 650;
	// a = x - 1;
	// line = x;
	// b = y;
	// while (y < 400)
	// {
	// 	while (x <= line)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, data->ceiling);
	// 		x++;
	// 	}
	// 	line += 1;
	// 	x = a;
	// 	a -= 1;
	// 	y++;
		// data->ceiling -= 1;
	// }
	
	// /* schuine lijn */
	// x = 50;
	// y = 250;
	// while (x < 150 && y < 500)
	// {
	// 	my_mlx_pixel_put(&img, x, y, data->ceiling);
	// 	x++;
	// 	y++;
	// }
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);

}
