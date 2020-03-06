/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 08:46:24 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/06 13:32:50 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	my_image_put(t_vars *v, t_tex *tex, int x, int y)
{
	char	*dst;
	char	*dst2;

	if (x < 0 || y < 0 || x > v->d->resx - 1 || y > v->d->resy - 1)
		return ;
	dst = v->g->addr + (y * v->g->line_length + x * (v->g->bits_per_pixel / 8));
	dst2 = tex->addr + ((int)tex->y_tex * tex->line_length + (int)tex->x_tex * (tex->bits_per_pixel / 8));
	*(unsigned int*)dst = *(unsigned int*)dst2;
}

int		my_mlx_pixel_putwall(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (v->map->map[(y / (int)v->tile_h)][x / (int)v->tile_w] == '1')
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