/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_exit_game.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:11:53 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:20:04 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		exit_game(t_vars *v)
{
	int	i;

	i = 0;
	if (!v->win)
		mlx_destroy_window(v->mlx, v->win);
	while (v->MAP[i])
	{
		free(v->MAP[i]);
		i++;
	}
	write(1, "\n-----> Thanks for playing <-----\n\n", 35);
	exit(0);
	return (1);
}

void	make_img(t_vars *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->d->resx, v->d->resy, "CUB3D");
	v->img1 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->img2 = mlx_new_image(v->mlx, v->d->resx, v->d->resy);
	v->addr = mlx_get_data_addr(v->img1, &v->bits_per_pixel,
	&v->line_length, &v->endian);
}

void	start_game(t_vars *v)
{
	make_img(v);
	PLAYER_X = v->PLAY_X;
	PLAYER_Y = v->PLAY_Y;
	player(v, 0);
	if (v->d->save == 1)
	{
		screenshot(v);
		exit_game(v);
	}
	mlx_hook(v->win, 2, 1L << 0, keypress, v);
	mlx_hook(v->win, 3, 1L << 1, keyrelease, v);
	mlx_hook(v->win, 17, 1L << 17, exit_game, v);
	mlx_loop_hook(v->mlx, &action, v);
	mlx_loop(v->mlx);
}
