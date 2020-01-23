/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 13:50:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/23 15:29:19 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print(t_flags *data)
{
	int		i;

	i = 0;
	// printf("[R0]    %s\n", data->r[0]);
	// printf("[R1]    %s\n", data->r[1]);
	printf("[RESX]  %d\n", data->resx);
	printf("[RESY]  %d\n", data->resy);
	// // printf("[NO]  %s\n", data->no);
	// // printf("[SO]  %s\n", data->so);
	// // printf("[WE]  %s\n", data->we);
	// // printf("[EA]  %s\n", data->ea);
	// // printf("[S]   %s\n", data->s);
	// printf("[F0]  %s\n", data->f[0]);
	// printf("[F1]  %s\n", data->f[1]);
	// printf("[F2]  %s\n", data->f[2]);
	// // printf("[C0]  %s\n", data->c[0]);
	// // printf("[C1]  %s\n", data->c[1]);
	// // printf("[C2]  %s\n", data->c[2]);
	// while (*data->map)
	// {
	// 	printf("[Row%3d]   %s\n", i, *data->map);
	// 	data->map++;
	// 	i++;
	// }
}
