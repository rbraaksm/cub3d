/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:04:08 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/13 21:27:17 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_vars *v, float rot)
{
	PLAYDIR += rot;
	if (PLAYDIR < 0)
		PLAYDIR += (2 * M_PI);
	if (PLAYDIR > (2 * M_PI))
		PLAYDIR -= (2 * M_PI);

}

void	move_player(t_vars *v, float move)
{
	float temp_x;
	float temp_y;

	temp_x = v->player->x;
	temp_y = v->player->y;
	v->player->x += sin(PLAYDIR) * move;
	if (v->MAP[(int)v->player->y][(int)v->player->x] == '1')
		v->player->x = temp_x;
	v->player->y += cos(PLAYDIR) * move;
	if (v->MAP[(int)v->player->y][(int)v->player->x] == '1')
		v->player->y = temp_y;
}

void	crab_player(t_vars *v, float move)
{
	float temp_x;
	float temp_y;
	float x_dir;
	float y_dir;

	temp_x = v->player->x;
	temp_y = v->player->y;
	x_dir = sin(PLAYDIR + M_PI / 2);
	y_dir = cos(PLAYDIR + M_PI / 2);
	v->player->x += x_dir * move;
	if (v->MAP[(int)v->player->y][(int)v->player->x] == '1')
		v->player->x = temp_x;
	v->player->y += y_dir * move;
	if (v->MAP[(int)v->player->y][(int)v->player->x] == '1')
		v->player->y = temp_y;
}

// void	set_zero(t_vars *v, char c)
// {
// 	v->player->move_l = 0;
// 	v->player->move_b = 0;
// 	v->player->move_r = 0;
// 	v->player->move_f = 0;
// 	if (c == 'l')
// 		v->player->move_l = 1;
// 	if (c == 'r')
// 		v->player->move_r = 1;
// 	if (c == 'f')
// 		v->player->move_f = 1;
// 	if (c == 'b')
// 		v->player->move_b = 1;
// }

// int		action(t_vars *v)
// {
// 	if (v->player->move_l)
// 		player(v, 0.08);
// 	if (v->player->move_r)
// 		player(v, -0.08);
// 	if (v->player->move_f)
// 		player(v, -0.08);
// 	if (v->player->move_b)
// 		player(v, 0.08);
// 	if (v->player->rotate_l)
// 		ft_view(v, 0.03);
// 	if (v->player->rotate_r)
// 		ft_view(v, -0.03);
// 	return (0);
// }

int		action(t_vars *v)
{
	rotate_player(v, v->player->look);
	move_player(v, v->player->walk);
	crab_player(v, v->player->crab);
	ft_view2(v);
	return (0);
}

// int		keyrelease(int keycode, t_vars *v)
// {
// 	if (keycode == 0)
// 		v->player->move_l = 0;
// 	if (keycode == 1)
// 		v->player->move_b = 0;
// 	if (keycode == 2)
// 		v->player->move_r = 0;
// 	if (keycode == 13)
// 		v->player->move_f = 0;
// 	if (keycode == 123)
// 		v->player->rotate_l = 0;
// 	if (keycode == 124)
// 		v->player->rotate_r = 0;
// 	return (0);
// }

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

// int		keypress(int keycode, t_vars *v)
// {
// 	if (keycode == 53)
// 		exit_game(v);
// 	if (keycode == 0)
// 		set_zero(v, 'l');
// 	if (keycode == 1)
// 		set_zero(v, 'b');
// 	if (keycode == 2)
// 		set_zero(v, 'r');
// 	if (keycode == 13)
// 		set_zero(v, 'f');
// 	if (keycode == 123)
// 	{
// 		v->player->rotate_l = 1;
// 		v->player->rotate_r = 0;
// 	}
// 	if (keycode == 124)
// 	{
// 		v->player->rotate_l = 0;
// 		v->player->rotate_r = 1;
// 	}
// 	return (0);
// }
