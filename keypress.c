/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:04:08 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:12:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		action(t_vars *v)
{
	if (v->player->move_l)
		player(v, 0.08);
	if (v->player->move_r)
		player(v, -0.08);
	if (v->player->move_f)
		player(v, -0.08);
	if (v->player->move_b)
		player(v, 0.08);
	if (v->player->rotate_l)
		ft_view(v, 0.05);
	if (v->player->rotate_r)
		ft_view(v, -0.05);
	return (0);
}

int		keyrelease(int keycode, t_vars *v)
{
	if (keycode == 0)
		v->player->move_l = 0;
	if (keycode == 1)
		v->player->move_b = 0;
	if (keycode == 2)
		v->player->move_r = 0;
	if (keycode == 13)
		v->player->move_f = 0;
	if (keycode == 123)
		v->player->rotate_l = 0;
	if (keycode == 124)
		v->player->rotate_r = 0;
	return (0);
}

int		keypress(int keycode, t_vars *v)
{
	if (keycode == 53)
		exit_game(v);
	if (keycode == 0)
		v->player->move_l = 1;
	if (keycode == 1)
		v->player->move_b = 1;
	if (keycode == 2)
		v->player->move_r = 1;
	if (keycode == 13)
		v->player->move_f = 1;
	if (keycode == 123)
		v->player->rotate_l = 1;
	if (keycode == 124)
		v->player->rotate_r = 1;
	return (0);
}
