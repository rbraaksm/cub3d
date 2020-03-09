/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/09 13:11:06 by rbraaksm      ########   odam.nl         */
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
	while (d->str[index] != '\0')
	{
		if (d->str[index] == 'R')
			d->r = (char **)ft_strdupchr(&(d->str)[index + 1], '\n');
		if (d->str[index] == 'N' && d->str[index + 1] == 'O')
			d->no = ft_strdupchr(&(d->str)[index + 2], '\n');
		if (d->str[index] == 'S' && d->str[index + 1] == 'O')
			d->so = ft_strdupchr(&(d->str)[index + 2], '\n');
		if (d->str[index] == 'W' && d->str[index + 1] == 'E')
			d->we = ft_strdupchr(&(d->str)[index + 2], '\n');
		if (d->str[index] == 'E' && d->str[index + 1] == 'A')
			d->ea = ft_strdupchr(&(d->str)[index + 2], '\n');
		if (d->str[index] == 'S' && d->str[index + 1] != 'O' && !d->s)
			d->s = ft_strdupchr(&(d->str)[index + 2], '\n');
		if (d->str[index] == 'F')
			d->f = (char **)ft_strdupchr(&(d->str)[index + 1], '\n');
		if (d->str[index] == 'C')
			d->c = (char **)ft_strdupchr(&(d->str)[index + 1], '\n');
		index++;
	}
	return (1);
}
