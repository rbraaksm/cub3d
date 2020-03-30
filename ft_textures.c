/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_textures.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/21 09:26:43 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	draw_roof(t_vars *v, int count)
{
	int				index;

	index = 0;
	while (index < count)
	{
		my_mlx_pixel_put2(v, v->i, index, v->color.ceiling);
		index++;
	}
}

void	draw_floor(t_vars *v, int count)
{
	int				index;

	index = v->RESY;
	while (index > count)
	{
		my_mlx_pixel_put2(v, v->i, index, v->color.floor);
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
	t_tex	*textures;

	textures = NULL;
	if (SIDE_HIT == 0)
		textures = v->textures->n_tex;
	else if (SIDE_HIT == 1)
		textures = v->textures->e_tex;
	else if (SIDE_HIT == 2)
		textures = v->textures->s_tex;
	else if (SIDE_HIT == 3)
		textures = v->textures->w_tex;
	return (textures);
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
}
