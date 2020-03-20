/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/20 18:07:27 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	printblock(t_vars *v, int row, int column)
{
	int				x;
	int				y;

	y = row * v->tile_h;
	while (y < ((row * v->tile_h) + v->tile_h))
	{
		x = column * v->tile_w;
		while (x < ((column * v->tile_w) + v->tile_w))
		{
			if (v->map->map[row][column] == '1')
				my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			else if (v->map->map[row][column] == '2')
				my_mlx_pixel_put(v, x, y, 0xffffff);
			x++;
		}
		y++;
	}
}

static void	make_grid2(t_vars *v)
{
	int		r;
	int		c;

	r = 0;
	while (r < v->map->row)
	{
		c = 0;
		while (c < v->map->column)
		{
			if (v->map->map[r][c] == '1' || v->map->map[r][c] == '2')
				printblock(v, r, c);
			c++;
		}
		r++;
	}
}

static void	make_grid(t_vars *v)
{
	int		x;
	int		y;
	int		z;

	z = 0;
	y = v->tile_h;
	while (z < v->map->row)
	{
		x = 0;
		while (x < v->RESX)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			x++;
		}
		y += v->tile_h;
		z++;
	}
	x = v->tile_w;
	z = 0;
	while (z < v->map->column)
	{
		y = 0;
		while (y < v->d->resy)
		{
			my_mlx_pixel_put(v, x, y, 0x8A2BE2);
			y++;
		}
		x += v->tile_w;
		z++;
	}
}

void	raydistance(t_vars *v)
{
	if (v->ray->raydist == 0)
	{
		v->ray->adjust = 1 / atan(M_PI / 6);
		v->ray->raydist = (v->ray->opp / (float)v->RESX) * 2;
		return ;
	}
	v->ray->opp -= v->ray->raydist;
	PLAYDIR = RAY_ANGLE + atan(v->ray->opp / v->ray->adjust);
}

void	ft_cleanview(t_vars *v)
{
	int		i;
	float	x;
	float	y;

	i = 0;
	RAY_ANGLE = PLAYDIR;
	while (i < (v->RESX))
	{
		x = v->player->x * v->tile_w;
		y = v->player->y * v->tile_h;
		while (my_mlx_pixel_putwall(v, x, y, 0x000000) == 1)
		{
			x += sin(PLAYDIR);
			y += cos(PLAYDIR);
		}
		raydistance(v);
		i++;
	}
	PLAYDIR = RAY_ANGLE;
	v->ray->opp = 1;
	if (PLAYDIR < 0)
		PLAYDIR += (2 * M_PI);
	if (PLAYDIR > (2 * M_PI))
		PLAYDIR -= (2 * M_PI);
}

void	check_dir(t_vars *v)
{
	if (PLAYDIR < 0)
		PLAYDIR += (2 * M_PI);
	if (PLAYDIR > (2 * M_PI))
		PLAYDIR -= (2 * M_PI);
}

void	ft_view(t_vars *v, float rot, unsigned int color)
{
	t_tex	*tex;
	float	x;
	float	y;

	v->i = 0;
	v->z = 0;
	tex = v->textures->sprite;
	ft_cleanview(v);
	make_grid(v);
	PLAYDIR += rot;
	check_dir(v);
	RAY_ANGLE = PLAYDIR;
	make_grid2(v);
	while (v->i < v->RESX)
	{
		raydistance(v);
		HAS_SPRITE = 0;
		x = v->player->x * v->tile_w;
		y = v->player->y * v->tile_h;
		while (my_mlx_pixel_putwall(v, x, y, color) == 1)
		{
			x += sin(PLAYDIR);
			y += cos(PLAYDIR);
		}
		find_side_delta(v);
		find_hit(v);
		draw_wall(v);
		if (SPRITE_I > 0)
			draw_sprite(v, tex);
		v->i++;
	}
	PLAYDIR = RAY_ANGLE;
	// v->ray->opp = 1;
	// if (v->g->active_img == 1)
	// {
		mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img1, 0, 0);
			mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
	// 	v->g->addr = mlx_get_data_addr(v->g->img2, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
	// 	v->g->active_img = 2;
	// }
	// else
	// {
	// 	mlx_put_image_to_window(v->g->mlx, v->g->win, v->g->img2, 0, 0);
	// 		// mlx_put_image_to_window(v->mlx, v->win, v->mapimg, 0, 0);
	// 	v->g->addr = mlx_get_data_addr(v->g->img1, &v->g->bits_per_pixel, &v->g->line_length, &v->g->endian);
	// 	v->g->active_img = 1;
	// }
}