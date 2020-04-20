/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/08 15:11:53 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/20 18:22:45 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			exit_game(t_vars *v, int x)
{
	int	i;

	i = 0;
	if (x == 1)
	{
		free(v->d->no);
		free(v->d->ea);
		free(v->d->so);
		free(v->d->we);
		free(v->d->s);
	}
	while (i < v->d->row_count)
	{
		free(v->d->map[i]);
		i++;
	}
	free(v->d->map);
	write(1, "Game closed\n", 12);
	exit(0);
	return (1);
}
