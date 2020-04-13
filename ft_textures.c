/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_textures.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/13 21:06:09 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_roof(t_vars *v, int count)
{
	int				index;

	index = 0;
	while (index < count)
	{
		my_mlx_pixel_put2(v, v->i, index, v->d->ceiling);
		index++;
	}
}

void	draw_floor(t_vars *v, int count)
{
	int				index;

	index = v->RESY;
	while (index > count)
	{
		my_mlx_pixel_put2(v, v->i, index, v->d->floor);
		index--;
	}
}

float	get_perc(t_vars *v)
{
	float	x_cord;
	float	y_cord;
	float	perc;

	x_cord = PLAYER_X + RAY_FINAL * RAYX;
	y_cord = PLAYER_Y + RAY_FINAL * RAYY;
	if (SIDE_HIT == 0 || SIDE_HIT == 2)
		perc = x_cord - (int)x_cord;
	else
		perc = y_cord - (int)y_cord;
	return (perc);
}

t_tex	*find_texture(t_vars *v)
{
	if (SIDE_HIT == 0)
		return (v->textures->n_tex);
	else if (SIDE_HIT == 1)
		return (v->textures->e_tex);
	else if (SIDE_HIT == 2)
		return (v->textures->s_tex);
	else
		return (v->textures->w_tex);
}

void	draw_wall(t_vars *v)
{
	t_tex	*tex;
	float	length;
	float	count;
	float	tmpcount;
	float	y;

	tex = find_texture(v);
	length = ((1 / WALLDIST) * v->RESY);
	count = (length / 2) + (v->RESY / 2);
	tmpcount = count;
	draw_roof(v, count);
	tex->x_tex = (float)tex->width * get_perc(v);
	tex->y_tex = tex->height - 1;
	y = (float)tex->height / (float)length;
	while (length > 0)
	{
		my_image_put(v, tex, v->i, count);
		count--;
		length--;
		tex->y_tex -= y;
	}
	draw_floor(v, tmpcount);

	// float	length;
	// float	count;
	// float	tmpcount;

	// length = ((1 / WALLDIST) * v->RESY);
	// count = (length / 2) + (v->RESY / 2);
	// tmpcount = count;
	// draw_roof(v, count);
	// while (length > 0)
	// {
	// 	my_mlx_pixel_put2(v, v->i, count, 0x555555);
	// 	count--;
	// 	length--;
	// }
	// draw_floor(v, tmpcount);
}
