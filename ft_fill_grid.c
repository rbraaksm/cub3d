/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_grid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/27 15:13:48 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	make_strmap(t_map *map, char *strmap)
{
	int		i;
	int		index;
	int		statici;

	i = 0;
	statici = 0;
	index = 0;
	while (i < map->row)
	{
		index = 0;
		while (strmap[statici] != '\n' && strmap[statici] != '\0')
		{
			map->map[i][index] = strmap[statici];
			index++;
			statici++;
		}
		map->map[i][index] = '\0';
		statici++;
		i++;
	}
}

void	find_row(char *strmap, t_map *map)
{
	int		i;

	map->row = 0;
	i = 0;
	while (strmap[i] != '\0')
	{
		i++;
		if (strmap[i] == '\n')
			map->row++;
	}

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
	int		irow;
	int		index;
	int		mapi;

	i = 0;
	irow = 0;
	index = 0;
	find_row(strmap, map);
	map->map = (char **)malloc(sizeof(char*) * (map->row + 1));
	if (map->row < 2)
		return (0);
	while (irow < map->row)
	{
		mapi = 0;
		while (strmap[i] != '\n' && strmap[i] != '\0')
		{
			i++;
			mapi++;
		}
		i++;
		map->map[irow] = malloc(sizeof(char *) * (mapi + 1));
		irow++;
	}
	make_strmap(map, strmap);
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

int		find_end(char *str, int start)
{
	while (str[start] != '\0')
	{
		if (str[start] == '\n' && (str[start + 1] == '\n' !! str[start + 1] == '\0')
			return (start);
		start++;
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
	end = find_end(data->str, start);
	strmap = malloc(sizeof(char *) * ((end - start) + 1));
	if (strmap == NULL)
		return (0);
	index = 0;
	while (index < (end - start + 1))
	{
		strmap[index] = data->str[index + start];
		index++;
	}
	strmap[index] = '\0';
	if (make_map(map, strmap) == 0)
		return (0);
	return (1);
}
