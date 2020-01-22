/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 18:13:21 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(t_flags *data)
{
	t_data	img;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		a;
	int		b;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, data->resx, data->resy, "CUB3D");
	img.img = mlx_new_image(mlx, data->resx, data->resy);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	
	/* Vierkant */
	y = 50;
	while (y < 150)
	{
		x = 50;
		while (x < 150)
		{
			my_mlx_pixel_put(&img, x, y, data->floor);
			x++;
		}
		y++;
	}
	
	/* Driehoek */
	y = 50;
	x = 600;
	a = x;
	while (y < 200)
	{
		while (x < 600)
		{
			my_mlx_pixel_put(&img, x, y, data->ceiling);
			x++;
		}
		a -= 1;
		x = a;
		y++;
	}

	/* schuine lijn */
	x = 50;
	y = 250;
	while (x < 150 && y < 500)
	{
		my_mlx_pixel_put(&img, x, y, data->ceiling);
		x++;
		y++;
	}

	/* cirkel */
	b = 0;
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
