/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:50:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/18 15:32:07 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print(t_vars *v)
{
	// int		i;

	// i = 0;
	// while (*v->map->map)
	// {
	// 	printf("[Row%3d]   %s\n", i, *v->map->map);
	// 	map->map++;
	// 	i++;
	// }
	printf("[SIDE X] %f\n", v->sidex);
	printf("[SIDE Y] %f\n", v->sidey);
	printf("[mapx] %d\n", v->mapx);
	printf("[mapy] %d\n", v->mapy);
	printf("[stepx] %d\n", v->stepx);
	printf("[stepy] %d\n", v->stepy);
	// printf("[posx] %d\n", v->map->posx);
	// printf("[rayx] %f\n\n", v->rayx);

	// printf("[posy] %d\n", v->map->posy);
	// printf("[rayy] %f\n\n", v->rayy);
	// printf("[walldist] %f\n\n", v->walldist);
}
