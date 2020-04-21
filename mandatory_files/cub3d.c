/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 10:58:18 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			free_function(t_data *d, int i)
{
	if (d->check >= 2)
		free(d->no);
	if (d->check >= 40)
		free(d->ea);
	if (d->check >= 200)
		free(d->s);
	if (d->check >= 4000)
		free(d->we);
	if (d->check >= 20000)
		free(d->s);
	if (i == 6 || i == 7)
		free(d->str);
	if (d->row_i == 0)
		return (0);
	while (d->row_i > 0)
	{
		free(d->map[d->row_i]);
		d->row_i--;
	}
	if (i == 7)
		free(d->map);
	return (0);
}

static int	check_cubfile(char **argv, t_data *d)
{
	if (make_string(argv, d) == 0)
		return (0);
	if (fill_parser(d) == 0)
		return (0);
	if (fill_grid(d) == 0)
		return (0);
	if (check_map(d) == 0)
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	t_vars	v;
	t_data	d;

	v.d = &d;
	if (check_input(argc, argv, &d) == 0)
		return (write(1, d.error, ft_strlen(d.error)));
	if (check_cubfile(argv, &d) == 0)
		return (write(1, d.error, ft_strlen(d.error)));
	start_game(&v);
	return (0);
}
