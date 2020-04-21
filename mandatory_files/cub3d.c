/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 18:56:55 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			free_function(t_vars *v, int i)
{
	if (v->check >= 2)
		free(v->no);
	if (v->check >= 40)
		free(v->ea);
	if (v->check >= 200)
		free(v->s);
	if (v->check >= 4000)
		free(v->we);
	if (v->check >= 20000)
		free(v->sp);
	if (i == 6 || i == 7)
		free(v->str);
	if (v->row_i == 0)
		return (0);
	while (v->row_i > 0)
	{
		free(v->map[v->row_i]);
		v->row_i--;
	}
	if (i == 7)
		free(v->map);
	return (0);
}

static int	check_cubfile(char **argv, t_vars *v)
{
	if (make_string(argv, v) == 0)
		return (0);
	if (fill_parser(v) == 0)
		return (0);
	if (fill_grid(v) == 0)
		return (0);
	if (check_map(v) == 0)
		return (0);
	return (1);
}

static void	struct_data(t_vars *v)
{
	v->player.x = 0;
	v->player.y = 0;
	v->ray.adjust = 1 / atan(M_PI / 6);
	v->img = 5;
	v->si = 0;
	v->player.walk = 0;
	v->player.crab = 0;
	v->row_i = 0;
	v->check = 0;
	v->resx = -1;
	v->resy = -1;
	v->fred = -1;
	v->fgreen = -1;
	v->fblue = -1;
	v->cred = -1;
	v->cgreen = -1;
	v->cblue = -1;
	v->ceiling = 0;
	v->floor = 0;
	v->error = "";
	v->no = NULL;
	v->ea = NULL;
	v->so = NULL;
	v->we = NULL;
	v->sp = NULL;
}

int			main(int argc, char **argv)
{
	t_vars	v;

	struct_data(&v);
	if (check_input(argc, argv, &v) == 0)
		return (write(1, v.error, ft_strlen(v.error)));
	if (check_cubfile(argv, &v) == 0)
		return (write(1, v.error, ft_strlen(v.error)));
	start_game(&v);
	return (0);
}
