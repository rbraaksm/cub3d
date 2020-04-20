/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite_sidehit.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:56:50 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 09:39:38 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	sprite_north(t_vars *v)
// {
// 	if (v->s[v->index].x_angle_incr > 0)
// 	{
// 		while (v->s[v->index].x_hit > v->s[v->index].x_hit_angle)
// 		{
// 			v->s[v->index].x_hit -= v->s[v->index].x_angle_incr;
// 			v->s[v->index].x_hit_angle -= v->s[v->index].x_incr;
// 		}
// 	}
// 	else
// 	{
// 		while (v->s[v->index].x_hit < v->s[v->index].x_hit_angle)
// 		{
// 			v->s[v->index].x_hit -= v->s[v->index].x_angle_incr;
// 			v->s[v->index].x_hit_angle -= v->s[v->index].x_incr;
// 		}
// 	}
// 	v->s[v->index].start = v->s[v->index].middle_x - (fabs(v->s[v->index].x_angle) / 2);
// 	v->s[v->index].perc = fabs(v->s[v->index].x_hit - v->s[v->index].start) / (v->s[v->index].x_angle);
// }

// void	sprite_east(t_vars *v)
// {
// 	if (v->s[v->index].x_angle_incr < 0)
// 	{
// 		while (v->s[v->index].y_hit > v->s[v->index].y_hit_angle)
// 		{
// 			v->s[v->index].y_hit += v->s[v->index].y_angle_incr;
// 			v->s[v->index].y_hit_angle += v->s[v->index].y_incr;
// 		}
// 	}
// 	else
// 	{
// 		while (v->s[v->index].y_hit < v->s[v->index].y_hit_angle)
// 		{
// 			v->s[v->index].y_hit += v->s[v->index].y_angle_incr;
// 			v->s[v->index].y_hit_angle += v->s[v->index].y_incr;
// 		}
// 	}
// 	v->s[v->index].start = v->s[v->index].middle_y - (fabs(v->s[v->index].y_angle) / 2);
// 	v->s[v->index].perc = fabs((v->s[v->index].y_hit - v->s[v->index].start) / (v->s[v->index].y_angle));
// }

// void	sprite_south(t_vars *v)
// {
// 	if (v->s[v->index].x_angle_incr > 0)
// 	{
// 		while (v->s[v->index].x_hit < v->s[v->index].x_hit_angle)
// 		{
// 			v->s[v->index].x_hit += v->s[v->index].x_angle_incr;
// 			v->s[v->index].x_hit_angle += v->s[v->index].x_incr;
// 		}
// 	}
// 	else
// 	{
// 		while (v->s[v->index].x_hit > v->s[v->index].x_hit_angle)
// 		{
// 			v->s[v->index].x_hit += v->s[v->index].x_angle_incr;
// 			v->s[v->index].x_hit_angle += v->s[v->index].x_incr;
// 		}
// 	}
// 	v->s[v->index].start = v->s[v->index].middle_x - (fabs(v->s[v->index].x_angle) / 2);
// 	v->s[v->index].perc = 1 - fabs((v->s[v->index].x_hit - v->s[v->index].start) / (v->s[v->index].x_angle));
// }

// void	sprite_west(t_vars *v)
// {
// 	if (v->s[v->index].x_angle_incr < 0)
// 	{
// 		while (v->s[v->index].y_hit < v->s[v->index].y_hit_angle)
// 		{
// 			v->s[v->index].y_hit -= v->s[v->index].y_angle_incr;
// 			v->s[v->index].y_hit_angle -= v->s[v->index].y_incr;
// 		}
// 	}
// 	else
// 	{
// 		while (v->s[v->index].y_hit > v->s[v->index].y_hit_angle)
// 		{
// 			v->s[v->index].y_hit -= v->s[v->index].y_angle_incr;
// 			v->s[v->index].y_hit_angle -= v->s[v->index].y_incr;
// 		}
// 	}
// 	v->s[v->index].start = v->s[v->index].middle_y - (fabs(v->s[v->index].y_angle) / 2);
// 	v->s[v->index].perc = 1 - fabs((v->s[v->index].y_hit - v->s[v->index].start) / (v->s[v->index].y_angle));
// }
