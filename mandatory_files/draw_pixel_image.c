/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_pixel_image.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 08:46:24 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/18 16:40:42 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_sprite_put(t_vars *v, int x, int y, float dest)
{
	char	*dst;
	char	*src;

	if (v->i < 0 || dest < 0 || v->i > v->d->resx || dest >= v->d->resy)
		return ;
	src = v->textures->sprite->addr + (y *
	v->textures->sprite->line_length + x *
	(v->textures->sprite->bits_per_pixel / 8));

	dst = v->addr + ((int)dest * v->line_length + v->i * (v->bits_per_pixel / 8));
	if (*(unsigned int*)src != 0x00000000)
		*(unsigned int*)dst = *(unsigned int*)src;
}

void	my_image_put(t_vars *v, t_tex *tex, int x, int y)
{
	char	*dst;
	char	*src;

	if (x < 0 || y < 0 || x > v->d->resx || y > (v->d->resy - 1))
		return ;
	src = tex->addr + ((int)tex->y_tex * tex->line_length + (int)tex->x_tex *
	(tex->bits_per_pixel / 8));
	dst = v->addr + (y * v->line_length + x * (v->bits_per_pixel / 8));
	*(unsigned int*)dst = *(unsigned int*)src;
}

void	my_mlx_pixel_put(t_vars *v, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= v->d->resx && y >= 0 && y < (v->d->resy - 1))
	{
		dst = v->addr + (y * v->line_length + x * (v->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}
