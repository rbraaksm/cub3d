/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 14:04:14 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdupchr(const char *s1, char c)
{
	char	*newstr;
	int		x;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	x = 0;
	while (s1[i2] == ' ')
		i2++;
	while (s1[i + i2] != c)
		i++;
	newstr = malloc(sizeof(char *) * (i + 1));
	if (!newstr)
		return (NULL);
	while (x < i)
	{
		newstr[x] = s1[x + i2];
		x++;
	}
	newstr[x + i2] = '\0';
	return (newstr);
}

int		fill_mapindex(t_flags *d)
{
	int		index;

	index = 0;
	while (STR[index] != '\0')
	{
		if (STR[index] == 'R')
			RES = (char **)ft_strdupchr(&(STR)[index + 1], '\n');
		if (STR[index] == 'N' && STR[index + 1] == 'O')
			NORTH = ft_strdupchr(&(STR)[index + 2], '\n');
		if (STR[index] == 'S' && STR[index + 1] == 'O')
			SOUTH = ft_strdupchr(&(STR)[index + 2], '\n');
		if (STR[index] == 'W' && STR[index + 1] == 'E')
			WEST = ft_strdupchr(&(STR)[index + 2], '\n');
		if (STR[index] == 'E' && STR[index + 1] == 'A')
			EAST = ft_strdupchr(&(STR)[index + 2], '\n');
		if (STR[index] == 'S' && STR[index + 1] != 'O' && !d->s)
			SPRITE = ft_strdupchr(&(STR)[index + 2], '\n');
		if (STR[index] == 'F')
			FSTR = (char **)ft_strdupchr(&(STR)[index + 1], '\n');
		if (STR[index] == 'C')
			CSTR = (char **)ft_strdupchr(&(STR)[index + 1], '\n');
		index++;
	}
	return (1);
}
