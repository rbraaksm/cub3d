/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:50:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/05 13:35:23 by rbraaksm      ########   odam.nl         */
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
	// printf("--------------------------\n");
	
	// printf("[pl x]    %f\n", v->player->x);
	// printf("[pl y]    %f\n", v->player->y);
	// printf("[angle]    %f\n", v->angle);
	// printf("[SIDE X]   %f\n", v->ray->sidex);
	// printf("[SIDE Y]   %f\n", v->ray->sidey);
	// printf("[mapx]     %d\n", v->mapx);
	// printf("[mapy]     %d\n", v->mapy);
	// printf("[rayx]     %f\n", v->rayx);
	// printf("[stepx]    %d\n", v->stepx);
	// printf("[rayy]     %f\n", v->rayy);
	// printf("[stepy]    %d\n", v->stepy);
	// printf("[posx]     %d\n", v->map->posx);
	// printf("[posy]     %d\n", v->map->posy);
	printf("[tile_w]   %f\n", v->tile_w);
	printf("[tile_h]   %f\n", v->tile_h);
	// printf("[walldist] %f\n", v->walldist);
	// printf("[playdir]  %f\n", v->playdir);
	// printf("[resx]  %d\n", v->data->resx);
	// printf("[ceiling]  	  %lx\n", v->color->ceiling);
	// printf("[cred]        %d\n", v->color->cred);
	// printf("[green]       %d\n", v->color->cgreen);
	// printf("[cblue]       %d\n", v->color->cblue);
	// printf("--------------------------\n");

}
