/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/16 16:31:09 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_str(t_data *d)
{
	if (d->check != CHECK && (d->str[d->i] == 32 || (d->str[d->i] > 8 &&
		d->str[d->i] < 14)))
		d->i = d->i + 1;
	else
		d->error = "ERROR: INDEX ISN'T CORRECT\n";
}

static void	find_values(t_data *d)
{
	d->i = 0;
	while (d->str[d->i] != '\0' && error_check(d, "") == 1 && d->check < CHECK)
	{
		if (d->str[d->i] == 'R')
			resolution(d, &(d->str)[d->i + 1]);
		else if (d->str[d->i] == 'N' && d->str[d->i + 1] == 'O' && !d->no)
			d->no = path(d, &(d->str)[d->i], 'N');
		else if (d->str[d->i] == 'S' && d->str[d->i + 1] == 'O' && !d->so)
			d->so = path(d, &(d->str)[d->i], 'S');
		else if (d->str[d->i] == 'W' && d->str[d->i + 1] == 'E' && !d->we)
			d->we = path(d, &(d->str)[d->i], 'W');
		else if (d->str[d->i] == 'E' && d->str[d->i + 1] == 'A' && !d->ea)
			d->ea = path(d, &(d->str)[d->i], 'E');
		else if (d->str[d->i] == 'S' && d->str[d->i + 1] != 'O' && !d->s)
			d->s = path(d, &(d->str)[d->i], 'O');
		else if (d->str[d->i] == 'F')
			data_floor(d, &(d->str)[d->i + 1]);
		else if (d->str[d->i] == 'C')
			data_ceiling(d, &(d->str)[d->i + 1]);
		else
			check_str(d);
	}
	d->start = d->i;
}

static void	colors(t_data *d)
{
	d->ceiling = d->ceiling + d->cblue % 16;
	d->ceiling = d->ceiling + d->cblue / 16 * 16;
	d->ceiling = d->ceiling + d->cgreen % 16 * pow(16, 2);
	d->ceiling = d->ceiling + d->cgreen / 16 * pow(16, 3);
	d->ceiling = d->ceiling + d->cred % 16 * pow(16, 4);
	d->ceiling = d->ceiling + d->cred / 16 * pow(16, 5);
	d->floor = d->floor + d->fblue % 16;
	d->floor = d->floor + d->fblue / 16 * 16;
	d->floor = d->floor + d->fgreen % 16 * pow(16, 2);
	d->floor = d->floor + d->fgreen / 16 * pow(16, 3);
	d->floor = d->floor + d->fred % 16 * pow(16, 4);
	d->floor = d->floor + d->fred / 16 * pow(16, 5);
}

static void	set_values(t_data *d)
{
	d->check = 0;
	d->resx = -1;
	d->resy = -1;
	d->fred = -1;
	d->fgreen = -1;
	d->fblue = -1;
	d->cred = -1;
	d->cgreen = -1;
	d->cblue = -1;
	d->ceiling = 0;
	d->floor = 0;
	d->error = "";
	d->no = NULL;
	d->ea = NULL;
	d->so = NULL;
	d->we = NULL;
	d->s = NULL;
}

int			fill_parser(t_data *d)
{
	set_values(d);
	find_values(d);
	if (d->check != CHECK)
		return (free_function(d, 0));
	colors(d);
	return (1);
}
