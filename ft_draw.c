/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_draw.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 08:46:24 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/16 19:51:22 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	my_sprite_put(t_vars *v, t_tex *tex, int x, int y)
{
	char	*dst;
	char	*src;

	if (x < 0 || y < 0 || x > v->d->resx || y > v->d->resy)
		return ;
	src = tex->addr + ((int)tex->y_tex * tex->line_length + (int)tex->x_tex * (tex->bits_per_pixel / 8));
	dst = v->g->addr + (y * v->g->line_length + x * (v->g->bits_per_pixel / 8));
	if (*(unsigned int*)src != 0x00000000)
		*(unsigned int*)dst = *(unsigned int*)src;
}

void	my_image_put(t_vars *v, t_tex *tex, int x, int y)
{
	char	*dst;
	char	*src;

	if (x < 0 || y < 0 || x > v->d->resx || y > v->d->resy)
		return ;
	src = tex->addr + ((int)tex->y_tex * tex->line_length + (int)tex->x_tex * (tex->bits_per_pixel / 8));
	dst = v->g->addr + (y * v->g->line_length + x * (v->g->bits_per_pixel / 8));
		*(unsigned int*)dst = *(unsigned int*)src;
}

int		my_mlx_pixel_putwall(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (v->MAP[(y / (int)v->tile_h)][x / (int)v->tile_w] == '1' ||
		v->MAP[(y / (int)v->tile_h)][x / (int)v->tile_w] == '2')
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

	if (x >= 0 && x <= v->d->resx && y >= 0 && y <= v->d->resy)
	{
		dst = v->g->addr + (y * v->g->line_length + x * (v->g->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}