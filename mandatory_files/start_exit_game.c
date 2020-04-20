/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_exit_game.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:11:53 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 16:41:50 by rbraaksm      ########   odam.nl         */
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
	v->check = 0;
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->img1 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->img2 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->addr = mlx_get_data_addr(v->img1, &v->bits_per_pixel,
	&v->line_length, &v->endian);
	v->no_mlx = mlx_init();
	v->no_img = mlx_xpm_file_to_image(v->no_mlx, v->d->no, &v->iw[0], &v->ih[0]);
	v->add[0] = mlx_get_data_addr(v->no_img, &v->bits[0], &v->ll[0], &v->en[0]);
	v->ea_mlx = mlx_init();
	v->ea_img = mlx_xpm_file_to_image(v->ea_mlx, v->d->ea, &v->iw[1], &v->ih[1]);
	v->add[1] = mlx_get_data_addr(v->ea_img, &v->bits[1], &v->ll[1], &v->en[1]);
	v->so_mlx = mlx_init();
	v->so_img = mlx_xpm_file_to_image(v->so_mlx, v->d->so, &v->iw[2], &v->ih[2]);
	v->add[2] = mlx_get_data_addr(v->so_img, &v->bits[2], &v->ll[2], &v->en[2]);
	v->we_mlx = mlx_init();
	v->we_img = mlx_xpm_file_to_image(v->we_mlx, v->d->we, &v->iw[3], &v->ih[3]);
	v->add[3] = mlx_get_data_addr(v->we_img, &v->bits[3], &v->ll[3], &v->en[3]);
	v->sp_mlx = mlx_init();
	v->sp_img = mlx_xpm_file_to_image(v->sp_mlx, v->d->s, &v->iw[4], &v->ih[4]);
	v->add[4] = mlx_get_data_addr(v->sp_img, &v->bits[4], &v->ll[4], &v->en[4]);
	// if (v->check != 5)
	// 	exit_game(v);
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
	// return ;
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
