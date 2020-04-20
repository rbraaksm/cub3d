/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 18:29:21 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	resolution_check(t_vars *v)
{
	v->screen_x = 0;
	v->screen_y = 0;
	mlx_get_screen_size(v->mlx, &v->screen_x, &v->screen_y);
	if (v->d->resx > v->screen_x && v->d->save != 1)
		v->d->resx = v->screen_x;
	if (v->d->resy > v->screen_y && v->d->save != 1)
		v->d->resy = v->screen_y;
}

static void	img(t_vars *v)
{
	v->img1 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->img2 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->no_img = XPM(v->no_mlx, v->d->no, &v->iw[0], &v->ih[0]);
	v->ea_img = XPM(v->ea_mlx, v->d->ea, &v->iw[1], &v->ih[1]);
	v->so_img = XPM(v->so_mlx, v->d->so, &v->iw[2], &v->ih[2]);
	v->we_img = XPM(v->we_mlx, v->d->we, &v->iw[3], &v->ih[3]);
	v->sp_img = XPM(v->sp_mlx, v->d->s, &v->iw[4], &v->ih[4]);
	if (!v->no_img || !v->ea_img || !v->so_img || !v->we_img || !v->sp_img ||
		!v->img1 || !v->img2)
	{
		write(1, "Invalid path for texture or sprite\n", 35);
		exit_game(v, 1);
	}
	free(v->d->no);
	free(v->d->ea);
	free(v->d->so);
	free(v->d->we);
	free(v->d->s);
}

static void	mlx(t_vars *v)
{
	v->mlx = mlx_init();
	v->no_mlx = mlx_init();
	v->ea_mlx = mlx_init();
	v->so_mlx = mlx_init();
	v->sp_mlx = mlx_init();
	v->we_mlx = mlx_init();
	if (!v->no_mlx || !v->ea_mlx || !v->so_mlx || !v->we_mlx || !v->sp_mlx ||
		!v->mlx)
	{
		write(1, "Making mlx failed\n", 18);
		exit_game(v, 1);
	}
}

static void	struct_values(t_vars *v)
{
	if (v->d->position == 'N')
		v->ray.playdir = M_PI;
	else if (v->d->position == 'E')
		v->ray.playdir = M_PI * 0.5;
	else if (v->d->position == 'S')
		v->ray.playdir = 0;
	else if (v->d->position == 'W')
		v->ray.playdir = M_PI * 1.5;
	v->ray.adjust = 1 / atan(M_PI / 6);
	v->player.x = v->d->play_x;
	v->player.y = v->d->play_y;
	v->active_img = 1;
	v->index = 0;
	mlx(v);
	img(v);
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->addr = ADDR(v->img1, &v->bits_per_pixel, &v->line_length, &v->endian);
	v->add[0] = ADDR(v->no_img, &v->bits[0], &v->ll[0], &v->en[0]);
	v->add[1] = ADDR(v->ea_img, &v->bits[1], &v->ll[1], &v->en[1]);
	v->add[2] = ADDR(v->so_img, &v->bits[2], &v->ll[2], &v->en[2]);
	v->add[3] = ADDR(v->we_img, &v->bits[3], &v->ll[3], &v->en[3]);
	v->add[4] = ADDR(v->sp_img, &v->bits[4], &v->ll[4], &v->en[4]);
	if (!v->add[0] || !v->add[1] || !v->add[2] || !v->add[3] || !v->add[4] ||
		!v->addr || !v->win)
		exit_game(v, 0);
}

void		window(t_vars *v)
{
	struct_values(v);
	rays(v);
	if (v->d->save == 1)
	{
		mlx_destroy_window(v->mlx, v->win);
		screenshot(v);
		exit_game(v, 0);
	}
	resolution_check(v);
	mlx_hook(v->win, 2, 1L << 0, keypress, v);
	mlx_hook(v->win, 3, 1L << 1, keyrelease, v);
	mlx_hook(v->win, 17, 1L << 17, exit_game, v);
	mlx_loop_hook(v->mlx, &action, v);
	mlx_loop(v->mlx);
}
