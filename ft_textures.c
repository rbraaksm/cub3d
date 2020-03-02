/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_textures.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/02 14:09:07 by rbraaksm      ########   odam.nl         */
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

float	get_perc(t_vars *v)
{
	float	x_cord;
	float	y_cord;
	float	left_side;
	float	perc;

	x_cord = v->play_x + (v->finaldist * v->rayx);
	y_cord = v->play_y + (v->finaldist * v->rayy);
	if (v->side_hit == 0 || v->side_hit == 2)
	{
		left_side = (int)x_cord % (int)v->tile_w;
		perc = (float)1 / (float)v->tile_h;
	}
	else
	{
		left_side = (int)y_cord % (int)v->tile_h;
		perc = (float)1 / (float)v->tile_h;
	}
	perc = perc * (float)left_side;
	return (perc);
}

t_tex	*find_texture(t_vars *v)
{
	t_tex	*textures;

	textures = NULL;
	if (v->side_hit == 0)
		textures = v->textures->n_tex;
	else if (v->side_hit == 1)
		textures = v->textures->e_tex;
	else if (v->side_hit == 2)
		textures = v->textures->s_tex;
	else if (v->side_hit == 3)
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
	length = ((1 / (float)v->walldist) * (float)v->d->resy) * 30;
	count = (length / 2) + (v->d->resy / 2);
	roof(v, i, count);
	floore(v, i, count);
	tex->x_tex = (float)tex->width * get_perc(v);
	tex->y_tex = 0;
	y = (float)tex->height / (float)length;
	while (length > 0)
	{
		my_image_put(v, tex, i, count);
		count--;
		length--;
		tex->y_tex += y;
	}
}

t_tex	*texture_info(t_vars *v, char *path)
{
	t_tex	*tex;
	int		width_img;
	int		height_img;

	tex = (t_tex *)malloc(sizeof(t_tex) * 1);
	if (tex == NULL)
		return (0);
	tex->mlx = mlx_init();
	tex->img = mlx_png_file_to_image(tex->mlx, path, &width_img, &height_img);
	if (tex->img == 0)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, &tex->line_length, &tex->endian);
	tex->win = v->g->win;
	tex->width = width_img;
	tex->height = height_img;
	return (tex);
}
