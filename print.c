/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:50:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/04/06 15:23:31 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print(t_flags *d)
{
	printf("--------------------------\n");
	printf("NORTH\n");
	printf("%s\n\n", NORTH);
	printf("SOUTH\n");
	printf("%s\n\n", SOUTH);
	printf("EAST\n");
	printf("%s\n\n", EAST);
	printf("WEST\n");
	printf("%s\n\n", WEST);
	printf("SPRITE\n");
	printf("%s\n", SPRITE);
	printf("--------------------------\n");
}
