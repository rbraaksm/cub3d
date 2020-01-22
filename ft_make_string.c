/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_make_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:33:27 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 14:56:38 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*pstr;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	pstr = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!pstr)
		return (NULL);
	while (i <= len)
	{
		pstr[i] = s1[i];
		i++;
	}
	return (pstr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	int			index;
	int			index2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	index = 0;
	index2 = 0;
	new = malloc(sizeof(char *) * (ft_strlen(s1) + (ft_strlen(s2) + 1)));
	if (!new)
		return (NULL);
	while (s1[index] != '\0')
	{
		new[index] = s1[index];
		index++;
	}
	while (s2[index2] != '\0')
	{
		new[index + index2] = s2[index2];
		index2++;
	}
	new[index + index2] = '\0';
	return (new);
}

int		make_string(char **argv, t_flags *data)
{
	char	buf[BUFFER_SIZE + 1];
	int		fd;
	int		ret;

	data->str = "";
	ret = 1;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		data->str = ft_strjoin((const char *)data->str, buf);
		if (data->str == NULL)
			return (0);
	}
	return (1);
}
