/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_textures.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/05 11:35:06 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	draw_roof_floor(t_vars *v, int i, int count)
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
	index = v->d->resy;
	color = v->color.floor;
	while (index > count)
	{
		my_mlx_pixel_put2(v, i, index, color);
		index--;
	}
}

float	get_perc(t_vars *v)
{
	float	x_cord;
	float	y_cord;
	float	perc;

	x_cord = v->player->x + (v->ray->finaldist * v->ray->rayx);
	y_cord = v->player->y + (v->ray->finaldist * v->ray->rayy);
	if (v->ray->side_hit == 0 || v->ray->side_hit == 2)
		perc = x_cord - (int)x_cord;
	else
		perc = y_cord - (int)y_cord;
	return (perc);
}

t_tex	*find_texture(t_vars *v)
{
	t_tex	*textures;

	textures = NULL;
	if (v->ray->side_hit == 0)
		textures = v->textures->n_tex;
	else if (v->ray->side_hit == 1)
		textures = v->textures->e_tex;
	else if (v->ray->side_hit == 2)
		textures = v->textures->s_tex;
	else if (v->ray->side_hit == 3)
		textures = v->textures->w_tex;
	return (textures);
}

void	ft_find_length(t_vars *v, int i)
{
	t_tex	*tex;
	float	length;
	float	count;
	float	y;

	tex = find_texture(v);
	length = ((1 / v->ray->walldist) * (float)v->d->resy);
	count = (length / 2) + (v->d->resy / 2);
	draw_roof_floor(v, i, count);
	tex->x_tex = (float)tex->width * get_perc(v);
	tex->y_tex = tex->height;
	y = (float)tex->height / (float)length;
	while (length > 0)
	{
		my_image_put(v, tex, i, count);
		count--;
		length--;
		tex->y_tex -= y;
	}
}
