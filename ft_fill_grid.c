/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_grid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 14:22:44 by rbraaksm      ########   odam.nl         */
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
			if (strmap[statici] == ' ')
				statici++;
			else
			{
				MAP[i][index] = strmap[statici];
				index++;
				statici++;
			}
		}
		MAP[i][index] = '\0';
		statici++;
		i++;
	}
}

void	find_row(char *strmap, t_map *map)
{
	int		i;

	map->row = 1;
	i = 0;
	while (strmap[i] != '\0')
	{
		i++;
		if (strmap[i] == '\n')
			map->row++;
	}
}

void	find_column(t_map *map, char *strmap)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = 0;
	map->column = 0;
	while (strmap[i] != '\0')
	{
		if (strmap[i] == '\n')
		{
			if (tmp < map->column)
			{
				tmp = map->column;
			}
			map->column = 0;
			i++;
		}
		i++;
		if (strmap[i] != ' ')
			map->column++;
	}
	map->column = tmp;
}

int		make_map(t_flags *d, t_map *map, char *strmap)
{
	int		i;
	int		irow;
	int		index;
	int		mapi;

	i = 0;
	irow = 0;
	index = 0;
	find_row(strmap, map);
	find_column(map, strmap);
	MAP = (char **)malloc(sizeof(char*) * (map->row + 1));
	if (map->row < 2)
		return (0);
	while (irow < map->row)
	{
		mapi = 0;
		while (strmap[i] != '\n' && strmap[i] != '\0')
		{
			i++;
			if (strmap[i] != ' ')
				mapi++;
		}
		i++;
		MAP[irow] = malloc(sizeof(char *) * (mapi + 1));
		irow++;
	}
	make_strmap(map, strmap);
	if (check_grid(d, map) == 0)
		return (0);
	return (1);
}

int		find_start(t_flags *d)
{
	int		index;

	index = 0;
	while (STR[index] != '\0')
	{
		if (STR[index] == '\n' && STR[index + 1] == '1')
			return (index + 1);
		index++;
	}
	return (0);
}

int		find_end(char *str, int start)
{
	while (str[start] != '\0')
	{
		if (str[start] == '\n' && (str[start + 1] == '\n'
		|| str[start + 1] == '\0'))
			return (start);
		start++;
	}
	return (start);
}

int		fill_grid(t_flags *d, t_map *map)
{
	char	*strmap;
	int		index;
	int		start;
	int		end;

	index = 0;
	start = find_start(d);
	if (start == 0)
		return (0);
	end = find_end(STR, start);
	strmap = malloc(sizeof(char *) * ((end - start) + 1));
	if (strmap == NULL)
		return (0);
	index = 0;
	while (index < (end - start + 1))
	{
		strmap[index] = STR[index + start];
		index++;
	}
	strmap[index] = '\0';
	if (make_map(d, map, strmap) == 0)
		return (0);
	return (1);
}
