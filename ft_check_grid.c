/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_grid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:09 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/28 08:37:09 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strchr(char c)
{
	char	*s1;
	int		i;

	s1 = "012NWSE";
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		first_last(char *str, int column)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (str[i] == '1' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			i += 2;
		else
			return (0);
	}
	return (1);
}

int		find_location(t_map *map)
{
	int		x;
	int		y;
	int		location;

	y = 0;
	location = 0;
	while (y < map->row)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			if ((map->map[y][x] == 'S' || map->map[y][x] == 'E' ||
			map->map[y][x] == 'W' || map->map[y][x] == 'N') && location == 0)
			{
				location = 1;
				map->posx = x;
				map->posy = y;
				x++;
			}
			if ((map->map[y][x] == 'S' || map->map[y][x] == 'E' ||
			map->map[y][x] == 'W' || map->map[y][x] == 'N') && location == 1)
				return (0);
			x++;
		}
		y++;
	}
	return (location);
}

int		middle(char *str, int column)
{
	int		i;
	int		checkrow;

	i = 1;
	checkrow = 0;
	if (str[0] != '1' || str[column - 1] != '1')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (0);
		i += 2;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(str[i]) == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int		check_grid(t_map *map)
{
	int		i;
	int		column;

	i = 0;
	column = 0;
	while (map->map[i][column] != '\0')
		column++;
	if (first_last(map->map[i], column) == 0)
		return (0);
	i++;
	if (find_location(map) == 0)
		return (0);
	while (i < (map->row - 1))
	{
		if (middle(map->map[i], column) == 0)
			return (0);
		i++;
	}
	if (first_last(map->map[i], column) == 0)
		return (0);
	return (1);
}
