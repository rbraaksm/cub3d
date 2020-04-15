/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/15 16:49:00 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_location(t_flags *d, int row, int column, char c)
{
	if (d->play_x == 0 && d->play_y == 0)
	{
		d->play_x = column + 0.5;
		d->play_y = row + 0.5;
		d->position = c;
	}
	else
	{
		d->error = "ERROR: TO MANY PLAYERS IN THE MAP\n";
		return (0);
	}
	return (1);
}

int		ft_strchr(t_flags *d, char c, int row, int column)
{
	char	*s1;
	int		i;

	s1 = "012NWSE";
	i = 0;
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		if (set_location(d, row, column, c) == 0)
			return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		fill_row(t_flags *d, int column, int start)
{
	int	i;

	i = 0;
	d->map[d->row_i] = (char *)malloc(sizeof(char *) * (d->column + 1));
	if (d->map[d->row_i] == NULL)
		return (free_function(d, 0));
	while (i < d->column)
	{
		d->map[d->row_i][i] = ' ';
		i++;
	}
	d->map[d->row_i][i] = '\0';
	i = 0;
	while (i < column)
	{
		d->map[d->row_i][i] = d->str[start + i];
		i++;
	}
	return (1);
}

int		check_str(t_flags *d)
{
	int	i;
	int	c;

	i = d->start;
	c = 0;
	d->column = 0;
	d->row_count = 1;
	d->error = "WRONG CHARACTER\n";
	while (d->str[i] != '\0')
	{
		if (d->str[i] != '0' && d->str[i] != '1' && d->str[i] != '2' &&
				d->str[i] != '\n' && d->str[i] != ' ' && d->str[i] != 'N' &&
				d->str[i] != 'E' && d->str[i] != 'S' && d->str[i] != 'W')
			return (0);
		c++;
		if (d->str[i] == '\n')
		{
			if (c > d->column)
				d->column = c;
			d->row_count++;
			c = 0;
		}
		i++;
	}
	return (1);
}

int		fill_grid(t_flags *d)
{
	int		start;
	int		c;

	d->row_i = 0;
	d->play_x = 0;
	d->play_y = 0;
	if (check_str(d) == 0)
		return (0);
	start = d->start;
	d->map = (char **)malloc(sizeof(char *) * (d->row_count));
	if (d->map == NULL)
		return (free_function(d, 6));
	while (d->row_i < d->row_count)
	{
		c = 0;
		while (d->str[c + start] != '\n' && d->str[c + start] != '\0')
			c++;
		if (fill_row(d, c, start) == 0)
			return (0);
		start = start + c + 1;
		d->row_i++;
	}
	free(d->str);
	return (1);
}
