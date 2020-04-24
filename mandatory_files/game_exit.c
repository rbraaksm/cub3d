/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_exit.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/22 09:39:35 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/23 15:03:42 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			free_function(t_vars *v)
{
	if (v->check >= 2)
		free(v->no);
	if (v->check >= 40)
		free(v->ea);
	if (v->check >= 200)
		free(v->so);
	if (v->check >= 4000)
		free(v->we);
	if (v->check >= 20000)
		free(v->sp);
	if (v->str != NULL)
		free(v->str);
	while ((v->row_i - 1) > 0)
	{
		free(v->map[v->row_i - 1]);
		v->row_i--;
	}
	if (v->map != NULL)
		free(v->map);
	if (v->fd)
		close(v->fd);
	write(1, v->error, ft_strlen(v->error));
	return (0);
}

int			exit_game(t_vars *v)
{
	close(v->fd);
	while ((v->row_i - 1) > 0)
	{
		free(v->map[v->row_i - 1]);
		v->row_i--;
	}
	free(v->map);
	if (v->img1)
		mlx_destroy_image(v->mlx, v->img1);
	if (v->img2)
		mlx_destroy_image(v->mlx, v->img2);
	if (v->no_img)
		mlx_destroy_image(v->no_mlx, v->no_img);
	if (v->ea_img)
		mlx_destroy_image(v->ea_mlx, v->ea_img);
	if (v->so_img)
		mlx_destroy_image(v->so_mlx, v->so_img);
	if (v->we_img)
		mlx_destroy_image(v->we_mlx, v->we_img);
	if (v->sp_img)
		mlx_destroy_image(v->sp_mlx, v->sp_img);
	write(1, "Game closed\n", 12);
	exit(0);
	return (1);
}
