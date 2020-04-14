/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 13:27:50 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_str(t_flags *d, int *i)
{
	if (d->str[*i] == ' ' || d->str[*i] == '1' || d->str[*i] == '2' ||
		d->str[*i] == '0' || d->str[*i] == '\n')
		*i = *i + 1;
	else if ((d->str[*i] == 'N' || d->str[*i] == 'E' || d->str[*i] == 'S' ||
			d->str[*i] == 'W') && (d->str[*i + 1] != '1' ||
			d->str[*i + 1] != '2' || d->str[*i + 1] != '0'))
		d->error = "ERROR: INDEX ISN'T CORRECT\n";
	else
		d->error = "ERROR: INDEX ISN'T CORRECT\n";
}

static void	find_values(t_flags *d)
{
	int	index;

	index = 0;
	while (d->str[index] != '\0' && error_check(d, "") == 1)
	{
		if (d->str[index] == 'R')
			resolution(d, &(d->str)[index + 1], &index);
		else if (d->str[index] == 'N' && d->str[index + 1] == 'O' && !d->no)
			north(d, &(d->str)[index], '\n', &index);
		else if (d->str[index] == 'S' && d->str[index + 1] == 'O' && !d->so)
			south(d, &(d->str[index]), '\n', &index);
		else if (d->str[index] == 'W' && d->str[index + 1] == 'E' && !d->we)
			west(d, &(d->str)[index], '\n', &index);
		else if (d->str[index] == 'E' && d->str[index + 1] == 'A' && !d->we)
			east(d, &(d->str)[index], '\n', &index);
		else if (d->str[index] == 'S' && d->str[index + 1] != 'O' && !d->s)
			sprite(d, &(d->str)[index], '\n', &index);
		else if (d->str[index] == 'F')
			data_floor(d, &(d->str)[index + 1], &index);
		else if (d->str[index] == 'C')
			data_ceiling(d, &(d->str)[index + 1], &index);
		else
			check_str(d, &index);
	}
}

static void	colors(t_flags *d)
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

static void	set_values(t_flags *d)
{
	d->check = 0;
	d->resx = 0;
	d->resy = 0;
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

int			fill_parser(t_flags *d)
{
	set_values(d);
	find_values(d);
	if (d->check != 42424242)
		return (0);
	colors(d);
	return (1);
}
