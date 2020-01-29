/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:50:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/29 15:13:30 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print(t_map *map)
{
	int		i;

	i = 0;
	while (*map->map)
	{
		printf("[Row%3d]   %s\n", i, *map->map);
		map->map++;
		i++;
	}
}
