/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/20 17:56:10 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		my_mlx_pixel_putwall(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (v->map->map[y / (int)v->tile_h][x / (int)v->tile_w] == '1' ||
		v->map->map[y / (int)v->tile_h][x / (int)v->tile_w] == '2')
		return (0);
	else
	{
		dst = v->addr + (y * v->line_length + x *
		(v->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
		return (1);
	}
}

void	my_mlx_pixel_put2(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < v->data->resx && y > 0 && y < v->data->resy)
	{
		dst = v->game->addr2 + (y * v->game->line_length2 + x * (v->game->bits_per_pixel2 / 8));
		*(unsigned int*)dst = color;
	}
}

void	ft_clean(t_vars *v)
{
	int	x;
	int	y;

	y = 0;
	while (y < v->data->resy)
	{
		x = 0;
		while (x < v->data->resx)
		{
			my_mlx_pixel_put2(v, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

// static void	make_grid(t_vars *v)
// {
// 	int		x;
// 	int		y;
// 	int		z;

// 	z = 0;
// 	y = v->tile_h;
// 	while (z < v->map->row)
// 	{
// 		x = 0;
// 		while (x < v->data->resx)
// 		{
// 			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
// 			x++;
// 		}
// 		y += v->tile_h;
// 		z++;
// 	}
// 	x = v->tile_w;
// 	z = 0;
// 	while (z < v->map->column)
// 	{
// 		y = 0;
// 		while (y < v->data->resy)
// 		{
// 			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
// 			y++;
// 		}
// 		x += v->tile_w;
// 		z++;
// 	}
// 	mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
// }

void	roof(t_vars *v, int i, int count)
{
	int		index;

	index = 0;
	while (index < count)
	{
		my_mlx_pixel_put2(v, i, index, 0xADD8E6);
		index++;
	}
}

void	floore(t_vars *v, int i, int count)
{
	int		index;

	index = v->data->resy;
	while (index > count)
	{
		my_mlx_pixel_put2(v, i, index, 0xff0000);
		index--;
	}
}

void	ft_find_length(t_vars *v, int i)
{
	int		index;
	double	length;
	double	middle;
	double	count;

	length = ((1 / (double)v->walldist) * (double)v->data->resy) * 10;
	middle = v->data->resy / 2;
	count = (length / 2) + middle;
	roof(v, i, count);
	floore(v, i, count);
	index = 0;
	while (index < length)
	{
		my_mlx_pixel_put2(v, i, count, 0xF08080);
		count--;
		index++;
	}
}

void	raydistance(t_vars *v)
{
	if (v->raydist == 0)
	{
		v->adjust = 1 / atan(M_PI / 6);
		v->raydist = (v->opp / (double)v->data->resx) * 2;
		return ;
	}
	v->opp -= v->raydist;
	v->tmpdir = v->playdir + atan(v->opp / v->adjust);
}

void	ft_view(t_vars *v, double rot, unsigned int color, char c)
{
	int		i;
	double	x;
	double	y;

	i = 0;
	if (v->angle < 0)
		v->angle += (2 * M_PI);
	if (v->angle > (2 * M_PI))
		v->angle -= (2 * M_PI);
	if (c == 'c')
		ft_view(v, 0, 0x000000, ' ');
	// make_grid(v);
	v->angle += rot;
	v->playdir = v->angle;
	v->tmpdir = v->angle;
	ft_clean(v);
	while (i <= v->data->resx)
	{
		x = (int)v->play_x;
		y = (int)v->play_y;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(v->tmpdir);
			y += cos(v->tmpdir);
		}
		ft_find_sidedelta(v);
		raydistance(v);
		ft_find_length(v, i);
		i++;
	}
	mlx_put_image_to_window(v->game->mlx2, v->game->win2, v->game->mapimg2, 0, 0);
	v->angle = v->playdir;
	v->opp = 1;
}
