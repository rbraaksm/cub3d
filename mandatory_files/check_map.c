/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:09 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 16:05:48 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	first_lines(t_vars *v, int *y)
{
	int	i;

	i = 0;
	while (v->map[*y][i] == ' ')
	{
		i++;
		if (v->map[*y][i] == '\0')
		{
			*y = *y + 1;
			i = 0;
		}
	}
	while (i < ft_strlen(v->map[*y]))
	{
		if (v->map[*y][i] == '1')
			i++;
		else if (v->map[*y][i] == ' ' && (v->map[*y + 1][i] == ' ' ||
		v->map[*y + 1][i] == '1'))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	middle_lines_2(t_vars *v, int y, int i)
{
	while (i < ft_strlen(v->map[y]))
	{
		if (ft_strchr(v, v->map[y][i], y, i) == 1)
			i++;
		else if (v->map[y][i] == ' ')
		{
			if (i < ft_strlen(v->map[y - 1]) &&
				!(v->map[y - 1][i] == ' ' || v->map[y - 1][i] == '1'))
				return (0);
			if (i < ft_strlen(v->map[y + 1]) &&
				!(v->map[y + 1][i] == ' ' || v->map[y + 1][i] == '1'))
				return (0);
			if (i != 0 && !(v->map[y][i - 1] == ' ' ||
				v->map[y][i - 1] == '1'))
				return (0);
			if (i + 1 != ft_strlen(v->map[y]) &&
				!(v->map[y][i + 1] == ' ' || v->map[y][i + 1] == '1'))
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}

static int	middle_lines(t_vars *v, int y)
{
	int i;

	i = 0;
	while (v->map[y][i] == ' ')
		i++;
	if (v->map[y][i] == '\0' && middle_lines_2(v, y, 0) == 0)
		return (0);
	else if (v->map[y][i] == '\0')
		return (1);
	if (v->map[y][i] != '1')
		return (0);
	if (middle_lines_2(v, y, 0) == 0)
		return (0);
	i = ft_strlen(v->map[y]) - 1;
	while (v->map[y][i] == ' ')
		i--;
	if (v->map[y][i] != '1')
		return (0);
	return (1);
}

static int	last_line(t_vars *v, int y)
{
	int	x;

	x = 0;
	while (v->map[y][x] != '\0')
	{
		if (v->map[y][x] == '1')
			x++;
		else if (v->map[y][x] == ' ' && (v->map[y - 1][x] == ' ' ||
				v->map[y - 1][x] == '1'))
			x++;
		else
			return (0);
	}
	return (1);
}

int			check_map(t_vars *v)
{
	int	i;

	i = 0;
	v->error = "ERROR: WRONG CHARACTER IN MAP\n";
	while (i < v->row_count)
	{
		if (i == 0)
			if (first_lines(v, &i) == 0)
				return (0);
		if (i > 0 && i < v->row_count - 1)
			if (middle_lines(v, i) == 0)
				return (0);
		if (i == v->row_count)
			if (last_line(v, i) == 0)
				return (0);
		i++;
	}
	if (v->player.x == 0 || v->player.y == 0)
	{
		v->error = "ERROR: NO PLAYER IN THE MAP\n";
		return (0);
	}
	v->error = "";
	return (1);
}
