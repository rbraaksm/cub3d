/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_player.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 15:47:58 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/06 13:39:13 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	player(t_vars *v, float move, unsigned int color)
{
	float		x;
	float		y;

	if (v->player->move_l == 1 || v->player->move_r == 1)
	{
		x = move * cos(v->ray->playdir);
		y = move * sin(v->ray->playdir);
	}
	else
	{
		x = -(move * sin(v->ray->playdir));
		y = move * cos(v->ray->playdir);
	}
	if (v->map->map[(int)(v->player->y - y)][(int)(v->player->x + x)] != '1' &&
		v->map->map[(int)(v->player->y - y)][(int)(v->player->x + x)] != '2')
	{
		ft_view(v, 0, 0x000000);
		v->player->x += x;
		v->player->y -= y;
		my_mlx_pixel_put(v, v->player->x * v->tile_w, v->player->y * v->tile_h, color);
		ft_view(v, 0, 0xffffff);
	}
}
