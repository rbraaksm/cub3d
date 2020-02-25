/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/25 13:08:38 by rbraaksm      ########   odam.nl         */
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

	if (x > 0 && x < v->d->resx && y > 0 && y < v->d->resy)
	{
		dst = v->g->addr + (y * v->g->line_length + x * (v->g->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

static void	make_grid(t_vars *v)
{
	int		x;
	int		y;
	int		z;

	z = 0;
	y = v->tile_h;
	while (z < v->map->row)
	{
		x = 0;
		while (x < v->d->resx)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			x++;
		}
		y += v->tile_h;
		z++;
	}
	x = v->tile_w;
	z = 0;
	while (z < v->map->column)
	{
		y = 0;
		while (y < v->d->resy)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			y++;
		}
		x += v->tile_w;
		z++;
	}
}

void	roof(t_vars *v, int i, int count)
{
	int				index;
	unsigned int	color;

	index = 0;
	color = v->color.ceiling;
	while (index < count)
	{
		my_mlx_pixel_put2(v, i, index, color);
		index++;
	}
}

void	floore(t_vars *v, int i, int count)
{
	int				index;
	unsigned int	color;

	index = v->d->resy;
	color = v->color.floor;
	while (index > count)
	{
		my_mlx_pixel_put2(v, i, index, color);
		index--;
	}
}

void	ft_find_length(t_vars *v, int i)
{
	int		index;
	float	length;
	float	middle;
	float	count;

	length = ((1 / (float)v->walldist) * (float)v->d->resy) * 10;
	middle = v->d->resy / 2;
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
		v->raydist = (v->opp / (float)v->d->resx) * 2;
		return ;
	}
	v->opp -= v->raydist;
	v->playdir = v->angle + atan(v->opp / v->adjust);
}

void	ft_cleanview(t_vars *v)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	v->angle = v->playdir;
	while (i <= v->d->resx)
	{
		x = (int)v->play_x;
		y = (int)v->play_y;
		while (my_mlx_pixel_putwall(v, x, y, 0x000000) == 1)
		{
			x += sin(v->playdir);
			y += cos(v->playdir);
		}
		raydistance(v);
		i++;
	}
	v->playdir = v->angle;
	v->opp = 1;
}

void	ft_view(t_vars *v, float rot, unsigned int color)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	if (v->playdir < 0)
		v->playdir += (2 * M_PI);
	if (v->playdir > (2 * M_PI))
		v->playdir -= (2 * M_PI);
	ft_cleanview(v);
	make_grid(v);
	v->playdir += rot;
	v->angle = v->playdir;
	while (i <= v->d->resx)
	{
		x = (int)v->play_x;
		y = (int)v->play_y;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(v->playdir);
			y += cos(v->playdir);
		}
		ft_find_sidedelta(v);
		raydistance(v);
		ft_find_length(v, i);
		i++;
	}
	v->playdir = v->angle;
	v->opp = 1;
	if (v->g->active_img == 1)
	{
		mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img1, 0, 0);
		v->g->addr = mlx_get_data_addr(v->g->img2, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
		v->g->active_img = 2;
	}
	else
	{
		mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img2, 0, 0);
		v->g->addr = mlx_get_data_addr(v->g->img1, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
		v->g->active_img = 1;
	}
}
