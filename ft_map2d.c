/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_map2d.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 14:13:44 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/07 15:07:32 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "./minilibx/mlx.h"

void	ft_make_2d(t_vars *v)
{
	PLAYER_X = v->PLAY_X;
	PLAYER_Y = v->PLAY_Y;
	player(v, 0);
}