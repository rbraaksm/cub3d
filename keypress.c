/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:04:08 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 11:08:12 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		action(t_vars *v)
{
	rotate_player(v, v->player->look);
	move_player(v, v->player->walk);
	crab_player(v, v->player->crab);
	ft_view(v);
	return (0);
}

int		keyrelease(int keycode, t_vars *v)
{
	if (keycode == 0)
		v->player->crab = 0;
	if (keycode == 1)
		v->player->walk = 0;
	if (keycode == 2)
		v->player->crab = 0;
	if (keycode == 13)
		v->player->walk = 0;
	if (keycode == 123)
		v->player->look = 0;
	if (keycode == 124)
		v->player->look = 0;
	return (0);
}

int		keypress(int keycode, t_vars *v)
{
	if (keycode == 53)
		exit_game(v);
	if (keycode == 0)
		v->player->crab = 0.05;
	else if (keycode == 2)
		v->player->crab = -0.05;
	else if (keycode == 1)
		v->player->walk = -0.05;
	else if (keycode == 13)
		v->player->walk = 0.05;
	else if (keycode == 123)
		v->player->look = 0.03;
	else if (keycode == 124)
		v->player->look = -0.03;
	return (0);
}
