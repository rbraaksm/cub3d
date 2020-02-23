/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/23 18:08:20 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdupchr(const char *s1, char c)
{
	char	*newstr;
	int		x;
	int		i;

	i = 0;
	x = 0;
	while (s1[i] != c)
		i++;
	newstr = malloc(sizeof(char *) * (i + 1));
	if (!newstr)
		return (NULL);
	while (x < i)
	{
		newstr[x] = s1[x];
		x++;
	}
	newstr[x] = '\0';
	return (newstr);
}

int		fill_mapindex(t_flags *data)
{
	int		index;

	index = 0;
	// data->s = NULL;
	while (data->str[index] != '\0')
	{
		if (data->str[index] == 'R')
			data->r = (char **)ft_strdupchr(&(data->str)[index + 1], '\n');
		if (data->str[index] == 'N' && data->str[index + 1] == 'O')
			data->no = ft_strdupchr(&(data->str)[index + 2], '\n');
		if (data->str[index] == 'S' && data->str[index + 1] == 'O')
			data->so = ft_strdupchr(&(data->str)[index + 2], '\n');
		if (data->str[index] == 'W' && data->str[index + 1] == 'E')
			data->we = ft_strdupchr(&(data->str)[index + 2], '\n');
		if (data->str[index] == 'E' && data->str[index + 1] == 'A')
			data->ea = ft_strdupchr(&(data->str)[index + 2], '\n');
		if (data->str[index] == 'S' && data->str[index + 1] != 'O' && !data->s)
			data->s = ft_strdupchr(&(data->str)[index + 2], '\n');
		if (data->str[index] == 'F')
			data->f = (char **)ft_strdupchr(&(data->str)[index + 1], '\n');
		if (data->str[index] == 'C')
			data->c = (char **)ft_strdupchr(&(data->str)[index + 1], '\n');
		index++;
	}
	return (1);
}
