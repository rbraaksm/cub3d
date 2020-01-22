/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_grid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 16:48:38 by rbraaksm      ########   odam.nl         */
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

void	find_row(char *strmap, int *row, int *column)
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
				*column = c;
			}
			r++;
		}
		i++;
		c++;
	}
	r += 1;
	*row = r;
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

int		make_map(t_flags *data, char *strmap)
{
	int		i;
	int		row;
	int		column;
	int		index;
	int		mapi;

	i = 0;
	index = 0;
	mapi = 0;
	find_row(strmap, &row, &column);
	data->map = (char **)malloc(sizeof(char*) * (row + 1));
	if (row < 3)
		return (0);
	while (i < row)
	{
		if (find_column(strmap, &mapi) != column)
			return (0);
		data->map[i] = malloc(sizeof(char *) * (column + 1));
		if (data->map[i] == NULL)
			return (0);
		make_strmap(data->map[i], strmap, &index, column);
		i++;
	}
	if (check_grid(data, row) == 0)
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

int		fill_grid(t_flags *data)
{
	char	*strmap;
	int		index;
	int		start;
	int		end;

	index = 0;
	start = find_start(data);
	if (start == 0)
		return (0);
	end = ft_strlen(data->str);
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
	if (make_map(data, strmap) == 0)
		return (0);
	return (1);
}
