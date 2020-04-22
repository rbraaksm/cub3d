/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:04:08 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 17:02:23 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rotate_player(t_vars *v, float rot)
{
	v->ray.playdir += rot;
	if (v->ray.playdir < 0)
		v->ray.playdir += (2 * M_PI);
	if (v->ray.playdir > (2 * M_PI))
		v->ray.playdir -= (2 * M_PI);
}

static void	crab_player(t_vars *v)
{
	float temp_x;
	float temp_y;

	temp_x = v->player.x;
	temp_y = v->player.y;
	if (v->player.crab != 0)
	{
		v->player.x += sin(v->ray.playdir + M_PI / 2) * v->player.crab;
		if (v->map[(int)v->player.y][(int)v->player.x] == '1')
			v->player.x = temp_x;
		v->player.y += cos(v->ray.playdir + M_PI / 2) * v->player.crab;
		if (v->map[(int)v->player.y][(int)v->player.x] == '1')
			v->player.y = temp_y;
	}
	if (v->player.walk != 0)
	{
		v->player.x += sin(v->ray.playdir) * v->player.walk;
		if (v->map[(int)v->player.y][(int)v->player.x] == '1')
			v->player.x = temp_x;
		v->player.y += cos(v->ray.playdir) * v->player.walk;
		if (v->map[(int)v->player.y][(int)v->player.x] == '1')
			v->player.y = temp_y;
	}
}

int		action(t_vars *v)
{
	rotate_player(v, v->player.look);
	// move_player(v, v->player.walk);
	crab_player(v);
	rays(v);
	return (0);
}

int		keyrelease(int keycode, t_vars *v)
{
	if (keycode == 0)
		v->player.crab = 0;
	if (keycode == 1)
		v->player.walk = 0;
	if (keycode == 2)
		v->player.crab = 0;
	if (keycode == 13)
		v->player.walk = 0;
	if (keycode == 123)
		v->player.look = 0;
	if (keycode == 124)
		v->player.look = 0;
	return (0);
}

int		keypress(int keycode, t_vars *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit_game(v);
	}
	if (keycode == 0)
		v->player.crab = 0.04;
	else if (keycode == 2)
		v->player.crab = -0.04;
	else if (keycode == 1)
		v->player.walk = -0.04;
	else if (keycode == 13)
		v->player.walk = 0.04;
	else if (keycode == 123)
		v->player.look = 0.03;
	else if (keycode == 124)
		v->player.look = -0.03;
	return (0);
}
