/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_view.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/03 12:26:26 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/15 20:59:35 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_dir(t_vars *v)
{
	if (v->ray->playdir < 0)
		v->ray->playdir += (2 * M_PI);
	if (v->ray->playdir > (2 * M_PI))
		v->ray->playdir -= (2 * M_PI);
}

void	ft_view(t_vars *v)
{
	float	start;
	float	incr;

	start = -1;
	incr = 2.0 / v->d->resx;
	v->i = 0;
	v->ray->angle = v->ray->playdir;
	v->ray->opp = 1;
	while (start <= 1)
	{
		v->ray->playdir = v->ray->angle + atan(start / v->ray->adjust);
		v->ray->sprite = 0;
		check_dir(v);
		find_side_delta(v);
		find_hit(v);
		draw_wall(v);
		if (v->index > 0)
			draw_sprite(v);
		start += incr;
		v->i++;
	}
	v->ray->playdir = v->ray->angle;
	put_img_2_win(v);
}
