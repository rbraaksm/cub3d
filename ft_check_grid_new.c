/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_grid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:09 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/27 14:59:22 by rbraaksm      ########   odam.nl         */
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

int		first(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1' || str[i] == ' ')
			i++;
		else
			return (0);
	}
	return (1);
}

int		find_location(char *str, int *location)
{
	while (*str)
	{
		if ((*str == 'S' || *str == 'E' ||
		*str == 'W' || *str == 'N') && *location == 0)
		{
			*location = 1;
			str++;
		}
		if ((*str == 'S' || *str == 'E' ||
		*str == 'W' || *str == 'N') && *location == 1)
			return (0);
		str++;
	}
	return (1);
}

int		middle(char *str, int *location)
{
	int		i;
	int		checkrow;

	i = 1;
	checkrow = 0;
	if (find_location(str, location) == 0)
		return (0);
	if (str[0] != '1' || str[ - 1] != '1')
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
	int		location;

	location = 0;
	if (first(map->map[0]) == 0)
		return (0);
	i = 1;
	// while (i < (map->row - 1))
	// {
	// 	if (middle(map->map[i], &location) == 0)
	// 		return (0);
	// 	i++;
	// }
	// if (location == 0)
	// 	return (0);
	// if (first_last(map->map[i], column) == 0)
	// 	return (0);
	return (1);
}
