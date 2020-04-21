/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 18:52:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_str(t_vars *v)
{
	if (v->check != CHECK && (v->str[v->i] == 32 ||
		(v->str[v->i] > 8 && v->str[v->i] < 14)))
		v->i = v->i + 1;
	else
		v->error = "ERROR: INDEX ISN'T CORRECT\n";
}

static void	find_values(t_vars *v)
{
	v->i = 0;
	while (v->str[v->i] != '\0' && error_check(v, "") == 1 && v->check < CHECK)
	{
		if (v->str[v->i] == 'R' && v->resx == -1)
			resolution(v, &(v->str)[v->i]);
		else if (v->str[v->i] == 'N' && v->str[v->i + 1] == 'O' && !v->no)
			v->no = path(v, &(v->str)[v->i], 'N');
		else if (v->str[v->i] == 'S' && v->str[v->i + 1] == 'O' && !v->so)
			v->so = path(v, &(v->str)[v->i], 'S');
		else if (v->str[v->i] == 'W' && v->str[v->i + 1] == 'E' && !v->we)
			v->we = path(v, &(v->str)[v->i], 'W');
		else if (v->str[v->i] == 'E' && v->str[v->i + 1] == 'A' && !v->ea)
			v->ea = path(v, &(v->str)[v->i], 'E');
		else if (v->str[v->i] == 'S' && v->str[v->i + 1] != 'O' && !v->sp)
			v->sp = path(v, &(v->str)[v->i], 'O');
		else if (v->str[v->i] == 'F')
			data_floor(v, &(v->str)[v->i + 1]);
		else if (v->str[v->i] == 'C')
			data_ceiling(v, &(v->str)[v->i + 1]);
		else
			check_str(v);
	}
	v->start = v->i;
}

static void	colors(t_vars *v)
{
	v->ceiling = v->ceiling + v->cblue % 16;
	v->ceiling = v->ceiling + v->cblue / 16 * 16;
	v->ceiling = v->ceiling + v->cgreen % 16 * pow(16, 2);
	v->ceiling = v->ceiling + v->cgreen / 16 * pow(16, 3);
	v->ceiling = v->ceiling + v->cred % 16 * pow(16, 4);
	v->ceiling = v->ceiling + v->cred / 16 * pow(16, 5);
	v->floor = v->floor + v->fblue % 16;
	v->floor = v->floor + v->fblue / 16 * 16;
	v->floor = v->floor + v->fgreen % 16 * pow(16, 2);
	v->floor = v->floor + v->fgreen / 16 * pow(16, 3);
	v->floor = v->floor + v->fred % 16 * pow(16, 4);
	v->floor = v->floor + v->fred / 16 * pow(16, 5);
}

int			fill_parser(t_vars *v)
{
	find_values(v);
	if (v->check != CHECK)
		return (free_function(v, 0));
	colors(v);
	return (1);
}
