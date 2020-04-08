/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   texture_data.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 16:46:57 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:14:00 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	west_texture(t_vars *v, char *path, t_tex *w_tex)
{
	int		width_img;
	int		height_img;

	w_tex->mlx = mlx_init();
	w_tex->img = mlx_png_file_to_image(w_tex->mlx,
	path, &width_img, &height_img);
	if (w_tex->img == 0)
		return ;
	w_tex->addr = mlx_get_data_addr(w_tex->img, &w_tex->bits_per_pixel,
	&w_tex->line_length, &w_tex->endian);
	w_tex->win = v->win;
	w_tex->width = width_img;
	w_tex->height = height_img;
	v->textures->w_tex = w_tex;
	free(v->WEST);
}

void	south_texture(t_vars *v, char *path, t_tex *s_tex)
{
	int		width_img;
	int		height_img;

	s_tex->mlx = mlx_init();
	s_tex->img = mlx_png_file_to_image(s_tex->mlx,
	path, &width_img, &height_img);
	if (s_tex->img == 0)
		return ;
	s_tex->addr = mlx_get_data_addr(s_tex->img, &s_tex->bits_per_pixel,
	&s_tex->line_length, &s_tex->endian);
	s_tex->win = v->win;
	s_tex->width = width_img;
	s_tex->height = height_img;
	v->textures->s_tex = s_tex;
	free(v->SOUTH);
}

void	east_texture(t_vars *v, char *path, t_tex *e_tex)
{
	int		width_img;
	int		height_img;

	e_tex->mlx = mlx_init();
	e_tex->img = mlx_png_file_to_image(e_tex->mlx, path,
	&width_img, &height_img);
	if (e_tex->img == 0)
		return ;
	e_tex->addr = mlx_get_data_addr(e_tex->img, &e_tex->bits_per_pixel,
	&e_tex->line_length, &e_tex->endian);
	e_tex->win = v->win;
	e_tex->width = width_img;
	e_tex->height = height_img;
	v->textures->e_tex = e_tex;
	free(v->EAST);
}

void	north_texture(t_vars *v, char *path, t_tex *n_tex)
{
	int		width_img;
	int		height_img;

	n_tex->mlx = mlx_init();
	n_tex->img = mlx_png_file_to_image(n_tex->mlx, path,
	&width_img, &height_img);
	if (n_tex->img == 0)
		return ;
	n_tex->addr = mlx_get_data_addr(n_tex->img, &n_tex->bits_per_pixel,
	&n_tex->line_length, &n_tex->endian);
	n_tex->win = v->win;
	n_tex->width = width_img;
	n_tex->height = height_img;
	v->textures->n_tex = n_tex;
	free(v->NORTH);
}

void	sprite_texture(t_vars *v, char *path, t_tex *sprite)
{
	int		width_img;
	int		height_img;

	sprite->mlx = mlx_init();
	sprite->img = mlx_png_file_to_image(sprite->mlx, path,
	&width_img, &height_img);
	if (sprite->img == 0)
		return ;
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel,
	&sprite->line_length, &sprite->endian);
	sprite->win = v->win;
	sprite->width = width_img;
	sprite->height = height_img;
	v->textures->sprite = sprite;
	free(v->SPRITE);
}
