/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:12:31 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	check_dir(t_vars *v)
{
	if (PLAYDIR < 0)
		PLAYDIR += (2 * M_PI);
	if (PLAYDIR > (2 * M_PI))
		PLAYDIR -= (2 * M_PI);
}

void	ft_view(t_vars *v, float rot)
{
	v->i = 0;
	PLAYDIR += rot;
	check_dir(v);
	RAY_ANGLE = PLAYDIR;
	v->ray->opp = 1;
	while (v->i < v->RESX)
	{
		raydistance(v);
		HAS_SPRITE = 0;
		check_dir(v);
		find_side_delta(v);
		find_hit(v);
		draw_wall(v);
		if (SPRITE_I > 0)
			draw_sprite(v);
		v->i++;
	}
	PLAYDIR = RAY_ANGLE;
	mlx_put_image_to_window(v->mlx, v->win, v->img1, 0, 0);
}
