/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_textures.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 13:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/27 20:03:30 by rbraaksm      ########   odam.nl         */
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
	tex->img = mlx_xpm_file_to_image(tex->mlx, path, &width_img, &height_img);
	if (tex->img == 0)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, &tex->line_length, &tex->endian);
	tex->win = v->g->win;
	tex->width = width_img;
	tex->height = height_img;
	return (tex);
}
