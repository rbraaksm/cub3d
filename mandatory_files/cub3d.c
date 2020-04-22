/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 14:14:19 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	struct_str(t_vars *v)
{
	v->str = NULL;
	v->map = NULL;
	v->no = NULL;
	v->ea = NULL;
	v->so = NULL;
	v->we = NULL;
	v->sp = NULL;
}

static void	struct_data(t_vars *v)
{
	struct_str(v);
	v->i = 0;
	v->player.x = 0;
	v->player.y = 0;
	v->ray.adjust = 1 / atan(M_PI / 6);
	v->img = 5;
	v->si = 0;
	v->player.walk = 0;
	v->player.crab = 0;
	v->row_i = 0;
	v->column = 0;
	v->row_count = 1;
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
}

int			main(int argc, char **argv)
{
	t_vars	v;

	struct_data(&v);
	if (check_input(argc, argv, &v) == 0)
		return (write(1, v.error, ft_strlen(v.error)));
	if (check_cubfile(argv, &v) == 0)
		return (free_function(&v));
	start_game(&v);
	return (0);
}
