/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_grid.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:09 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 13:28:39 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	first_line(t_flags *d)
{
	int	i;

	i = 0;
	d->error = "ERROR: FIRST LINE ISN'T CORRECT\n";
	while (i < ft_strlen(d->map[0]))
	{
		if (d->map[0][i] == '1')
			i++;
		else if (d->map[0][i] == ' ' && (d->map[1][i] == ' ' ||
		d->map[1][i] == '1'))
			i++;
		else
			return (0);
	}
	d->error = "";
	return (1);
}

static int	middle_lines_2(t_flags *d, int y, int i)
{
	while (i < ft_strlen(d->map[y]))
	{
		if (ft_strchr(d, d->map[y][i], y, i) == 1)
			i++;
		else if (d->map[y][i] == ' ')
		{
			if (i < ft_strlen(d->map[y - 1]) &&
				!(d->map[y - 1][i] == ' ' || d->map[y - 1][i] == '1'))
				return (0);
			if (i < ft_strlen(d->map[y + 1]) &&
				!(d->map[y + 1][i] == ' ' || d->map[y + 1][i] == '1'))
				return (0);
			if (i != 0 && !(d->map[y][i - 1] == ' ' ||
				d->map[y][i - 1] == '1'))
				return (0);
			if (i + 1 != ft_strlen(d->map[y]) &&
				!(d->map[y][i + 1] == ' ' || d->map[y][i + 1] == '1'))
				return (0);
			i++;
		}
		else
			return (0);
	}
	d->error = "";
	return (1);
}

static int	middle_lines(t_flags *d, int y)
{
	int i;

	i = 0;
	d->error = "ERROR: MAP ISN'T CORRECT\n";
	while (d->map[y][i] == ' ')
		i++;
	if (d->map[y][i] != '1')
		return (0);
	i = 0;
	if (middle_lines_2(d, y, i) == 0)
		return (0);
	i = ft_strlen(d->map[y]) - 1;
	while (d->map[y][i] == ' ')
		i--;
	if (d->map[y][i] != '1')
		return (0);
	d->error = "";
	return (1);
}

static int	last_line(t_flags *d, int y)
{
	int	x;

	x = 0;
	d->error = "ERROR: LAST LINE ISN'T CORRECT\n";
	while (d->map[y][x] != '\0')
	{
		if (d->map[y][x] == '1')
			x++;
		else if (d->map[y][x] == ' ' && (d->map[y - 1][x] == ' ' ||
				d->map[y - 1][x] == '1'))
			x++;
		else
			return (0);
	}
	d->error = "";
	return (1);
}

int			check_grid(t_flags *d)
{
	int	i;

	i = 0;
	while (i < d->row_count)
	{
		if (i == 0)
			if (first_line(d) == 0)
				return (0);
		if (i > 0 && i < d->row_count - 1)
			if (middle_lines(d, i) == 0)
				return (0);
		if (i == d->row_count - 1)
			if (last_line(d, i) == 0)
				return (0);
		i++;
	}
	if (d->play_x == 0 || d->play_y == 0)
	{
		d->error = "ERROR: NO PLAYER IN THE MAP\n";
		return (0);
	}
	return (1);
}
