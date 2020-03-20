/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_struct.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 09:29:23 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/20 13:15:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

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

void	struct_info(t_vars *v)
{
	v->textures->n_tex = texture_info(v, v->d->no);
	v->textures->e_tex = texture_info(v, v->d->ea);
	v->textures->s_tex = texture_info(v, v->d->so);
	v->textures->w_tex = texture_info(v, v->d->we);
	v->textures->sprite = texture_info(v, v->d->s);
	if (v->map->pos == 'N')
		v->ray->playdir = M_PI;
	else if (v->map->pos == 'E')
		v->ray->playdir = M_PI * 0.5;
	else if (v->map->pos == 'S')
		v->ray->playdir = 0;
	else if (v->map->pos == 'W')
		v->ray->playdir = M_PI * 1.5;
	v->tile_w = v->d->resx / v->map->column;
	v->tile_h = v->d->resy / v->map->row;
	v->ray->raydist = 0;
	v->ray->opp = 1;
	v->player->move_f = 0;
	v->player->move_b = 0;
	v->player->move_l = 0;
	v->player->move_r = 0;
	v->player->rotate_r = 0;
	v->player->rotate_l = 0;
	v->g->active_img = 1;
	v->ray->side_hit = 10;
	v->ray->sprite_hit = 10;
	v->ray->sprite = 0;
	SPRITE_I = 0;
}
