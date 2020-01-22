/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mapindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 14:59:33 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		count;
	size_t		index;

	count = 0;
	if (!dst)
		return (0);
	while (src[count] != '\0')
		count++;
	if (!dstsize)
		return (count);
	index = 0;
	while (src[index] != '\0' && index < (dstsize - 1))
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (count);
}

int		start_index(const char *s1)
{
	int		i;

	i = 0;
	if (s1[i] == 'R' || s1[i] == 'F' || s1[i] == 'C')
	{
		while (s1[i] != '\n')
		{
			if (s1[i] >= '0' && s1[i] <= '9')
				return (i);
			i++;
		}
	}
	else
		while (s1[i] != '.')
			i++;
	return (i);
}

char	*ft_strdupchr(const char *s1, char c)
{
	char	*newstr;
	int		x;
	int		i;
	int		i2;

	i = start_index(s1);
	i2 = i;
	while (s1[i] != c)
		i++;
	if (!*s1 || i2 >= ft_strlen(s1))
		return (ft_strdup(""));
	x = ft_strlen(s1) - i2;
	if (x < (i - i2))
		newstr = (char *)malloc(sizeof(char) * (x + 1));
	else
		newstr = (char *)malloc(sizeof(char) * ((i - i2) + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1 + i2, ((i - i2) + 1));
	return (newstr);
}

int		fill_mapindex(t_flags *data)
{
	int		index;

	index = 0;
	data->s = NULL;
	while (data->str[index] != '\0')
	{
		if (data->str[index] == 'R')
			data->r = (char **)ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'N' && data->str[index + 1] == 'O')
			data->no = ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'S' && data->str[index + 1] == 'O')
			data->so = ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'W' && data->str[index + 1] == 'E')
			data->we = ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'E' && data->str[index + 1] == 'A')
			data->ea = ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'S' && data->str[index + 1] != 'O' && !data->s)
			data->s = ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'F')
			data->f = (char **)ft_strdupchr(&(data->str)[index], '\n');
		if (data->str[index] == 'C')
			data->c = (char **)ft_strdupchr(&(data->str)[index], '\n');
		index++;
	}
	return (1);
}
