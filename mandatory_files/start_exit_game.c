/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_exit_game.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:11:53 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 14:53:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_game(t_vars *v)
{
	int	i;

	i = 0;
	while (i < v->d->row_count)
	{
		free(v->d->map[i]);
		i++;
	}
	free(v->d->map);
	write(1, "Game closed\n", 12);
	exit(0);
	return (1);
}

static void	img(t_vars *v)
{
	v->img1 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->img2 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->no_img = XPM(v->no_mlx, v->d->no, &v->img_width[0], &v->img_height[0]);
	v->ea_img = XPM(v->ea_mlx, v->d->ea, &v->img_width[1], &v->img_height[1]);
	v->so_img = XPM(v->so_mlx, v->d->so, &v->img_width[2], &v->img_height[2]);
	v->we_img = XPM(v->we_mlx, v->d->we, &v->img_width[3], &v->img_height[3]);
	v->sp_img = XPM(v->sp_mlx, v->d->s, &v->img_width[4], &v->img_height[4]);
	if (!v->no_img || !v->ea_img || !v->so_img || !v->we_img || !v->sp_img ||
		!v->img1 || !v->img2)
	{
		write(1, "Invalid path for texture or sprite\n", 35);
		exit_game(v);
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
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "CUB3D");
	if (!v->no_mlx || !v->ea_mlx || !v->so_mlx || !v->we_mlx || !v->sp_mlx ||
		!v->mlx || !v->win)
	{
		write(1, "Making mlx/win failed\n", 22);
		exit_game(v);
	}
}

static void	make_img(t_vars *v)
{
	mlx(v);
	img(v);
	v->add[5] = ADDR(v->img1, &v->bits[5], &v->ll[5], &v->en[5]);
	v->add[6] = ADDR(v->img2, &v->bits[5], &v->ll[5], &v->en[5]);
	v->add[0] = ADDR(v->no_img, &v->bits[0], &v->ll[0], &v->en[0]);
	v->add[1] = ADDR(v->ea_img, &v->bits[1], &v->ll[1], &v->en[1]);
	v->add[2] = ADDR(v->so_img, &v->bits[2], &v->ll[2], &v->en[2]);
	v->add[3] = ADDR(v->we_img, &v->bits[3], &v->ll[3], &v->en[3]);
	v->add[4] = ADDR(v->sp_img, &v->bits[4], &v->ll[4], &v->en[4]);
	if (!v->add[0] || !v->add[1] || !v->add[2] || !v->add[3] || !v->add[4] ||
		!v->add[5] || !v->add[6] || !v->win)
	{
		write(1, "Get data addr failed\n", 21);
		exit_game(v);
	}
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
	v->img = 5;
	v->si = 0;
}

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

void		start_game(t_vars *v)
{
	make_img(v);
	rays(v);
	if (v->d->save == 1)
	{
		mlx_destroy_window(v->mlx, v->win);
		screenshot(v);
		exit_game(v);
	}
	resolution_check(v);
	mlx_hook(v->win, 2, 1L << 0, keypress, v);
	mlx_hook(v->win, 3, 1L << 1, keyrelease, v);
	mlx_hook(v->win, 17, 1L << 17, exit_game, v);
	mlx_loop_hook(v->mlx, &action, v);
	mlx_loop(v->mlx);
}
