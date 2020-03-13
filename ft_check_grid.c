/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_grid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:09 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 14:22:23 by rbraaksm      ########   odam.nl         */
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

int		first_last(t_flags *d, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			i++;
		else
		{
			ERROR = "FIRST/LAST LINE ISN'T CORRECT";
			return (0);
		}
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
		while (MAP[y][x] != '\0')
		{
			if ((MAP[y][x] == 'S' || MAP[y][x] == 'E' ||
			MAP[y][x] == 'W' || MAP[y][x] == 'N') && location == 0)
			{
				location = 1;
				map->posx = x;
				map->posy = y;
				map->pos = MAP[y][x];
				x++;
			}
			if ((MAP[y][x] == 'S' || MAP[y][x] == 'E' ||
			MAP[y][x] == 'W' || MAP[y][x] == 'N') && location == 1)
				return (0);
			x++;
		}
		y++;
	}
	return (location);
}

int		middle(t_map *map, char *str)
{
	int		i;

	if (str[0] != '1' || str[map->column - 1] != '1')
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_grid(t_flags *d, t_map *map)
{
	int		i;

	i = 0;
	if (first_last(d, MAP[i]) == 0)
		return (0);
	i++;
	if (find_location(map) == 0)
		return (0);
	while (i < (map->row - 1))
	{
		if (middle(map, MAP[i]) == 0)
			return (0);
		i++;
	}
	if (first_last(d, MAP[i]) == 0)
		return (0);
	return (1);
}
