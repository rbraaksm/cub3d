/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:50:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/19 18:00:08 by rbraaksm      ########   odam.nl         */
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
	printf("--------------------------\n");
	// printf("[angle] %f\n", v->angle);
	// printf("[30] %f\n", (M_PI / 6));
	// printf("[SIDE X] %f\n", v->sidex);
	// printf("[SIDE Y] %f\n", v->sidey);
	// printf("[mapx] %d\n", v->mapx);
	// printf("[mapy] %d\n", v->mapy);
	// printf("[rayx]     %f\n", v->rayx);
	// printf("[stepx]    %d\n", v->stepx);
	// printf("[rayy]     %f\n", v->rayy);
	// printf("[stepy]    %d\n", v->stepy);
	// printf("[posx] %d\n", v->map->posx);
	// printf("[posy] %d\n", v->map->posy);
	// printf("[tile_w] %f\n\n", v->tile_w);
	// printf("[tile_h] %f\n\n", v->tile_h);
	printf("[walldist] %f\n\n", v->walldist);
	printf("--------------------------\n");

}
