/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_grid_old.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/27 13:38:40 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		make_strmap(char *newstr, char *strmap, int *index, int column)
{
	int		i;
	int		ind;

	i = 0;
	ind = 0;
	while (ind < column && *strmap != '\0')
	{
		newstr[ind] = strmap[ind + *index];
		ind++;
	}
	newstr[ind] = '\0';
	*index = *index + ind + 1;
	return (1);
}

void	find_row(char *strmap, t_map *map)
{
	int		i;
	int		check;
	int		c;
	int		r;

	i = 0;
	r = 0;
	c = 0;
	check = 0;
	while (strmap[i] != '\0')
	{
		if (strmap[i] == '\n')
		{
			if (check == 0)
			{
				check = 1;
				map->column = c;
			}
			r++;
		}
		i++;
		c++;
	}
	r += 1;
	map->row = r;
}

int		find_column(char *strmap, int *mapi)
{
	int		column;
	int		i;

	column = 0;
	i = *mapi;
	while (strmap[i] != '\0')
	{
		if (strmap[i] == '\n')
		{
			*mapi = i + 1;
			return (column);
		}
		i++;
		column++;
	}
	return (column);
}

int		make_map(t_map *map, char *strmap)
{
	int		i;
	int		index;
	int		mapi;

	i = 0;
	index = 0;
	mapi = 0;
	find_row(strmap, map);
	map->map = (char **)malloc(sizeof(char*) * (map->row + 1));
	if (map->row < 2)
		return (0);
	while (i < map->row)
	{
		if (find_column(strmap, &mapi) != map->column)
			return (0);
		map->map[i] = malloc(sizeof(char *) * (map->column + 1));
		if (map->map[i] == NULL)
			return (0);
		make_strmap(map->map[i], strmap, &index, map->column);
		i++;
	}
	if (check_grid(map) == 0)
		return (0);
	return (1);
}

int		find_start(t_flags *data)
{
	int		index;

	index = 0;
	while (data->str[index] != '\0')
	{
		if (data->str[index] == '\n' && data->str[index + 1] == '1')
			return (index + 1);
		index++;
	}
	return (0);
}

int		find_end(char *str)
{
	int		i;

	i = ft_strlen(str);
	while (i > 0)
	{
		i--;
		if (str[i] == '1')
			return (i);
	}
	return (0);
}

int		fill_grid(t_flags *data, t_map *map)
{
	char	*strmap;
	int		index;
	int		start;
	int		end;

	index = 0;
	start = find_start(data);
	if (start == 0)
		return (0);
	end = find_end(data->str);
	strmap = malloc(sizeof(char *) * ((end - start) + 1));
	if (strmap == NULL)
		return (0);
	index = 0;
	while (index < (end - start))
	{
		strmap[index] = data->str[index + start];
		index++;
	}
	strmap[index] = '\0';
	if (make_map(map, strmap) == 0)
		return (0);
	return (1);
}
