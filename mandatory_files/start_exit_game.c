/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_exit_game.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:11:53 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 13:59:55 by rbraaksm      ########   odam.nl         */
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

static void	make_img(t_vars *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->img1 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->img2 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->addr = mlx_get_data_addr(v->img1, &v->bits_per_pixel,
	&v->line_length, &v->endian);
	v->mlx_tex5 = mlx_init();
	v->it5 = mlx_xpm_file_to_image(v->mlx_tex5, v->d->s, &v->iw, &v->ih);
	v->addt = mlx_get_data_addr(v->it5, &v->bppt, &v->llt, &v->et);
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
