/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 18:55:04 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fill_row(t_vars *v, int column, int start)
{
	int	i;

	i = 0;
	v->map[v->row_i] = (char *)malloc(sizeof(char *) * (v->column + 1));
	if (v->map[v->row_i] == NULL)
		return (free_function(v, 7));
	while (i < v->column)
	{
		v->map[v->row_i][i] = ' ';
		i++;
	}
	v->map[v->row_i][i] = '\0';
	i = 0;
	while (i < column)
	{
		v->map[v->row_i][i] = v->str[start + i];
		i++;
	}
	return (1);
}

static int	find_column_row(t_vars *v)
{
	int	i;
	int	c;

	i = v->start;
	c = 0;
	v->column = 0;
	v->row_count = 1;
	while (v->str[i] != '\0')
	{
		c++;
		if (v->str[i] == '\n')
		{
			if (c > v->column)
				v->column = c;
			v->row_count++;
			c = 0;
		}
		i++;
	}
	return (1);
}

int			fill_grid(t_vars *v)
{
	int		start;
	int		c;

	if (find_column_row(v) == 0)
		return (0);
	start = v->start;
	v->map = (char **)malloc(sizeof(char *) * (v->row_count));
	if (v->map == NULL)
		return (free_function(v, 6));
	while (v->row_i < v->row_count)
	{
		c = 0;
		while (v->str[c + start] != '\n' && v->str[c + start] != '\0')
			c++;
		if (fill_row(v, c, start) == 0)
			return (0);
		start = start + c + 1;
		v->row_i++;
	}
	free(v->str);
	return (1);
}
