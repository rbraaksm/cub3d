/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_strings.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:37:22 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/15 12:35:54 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check(t_flags *d, char c)
{
	if (c == 'N')
		d->check += 2;
	else if (c == 'E')
		d->check += 40;
	else if (c == 'S')
		d->check += 200;
	else if (c == 'W')
		d->check += 4000;
	else if (c == 'O')
		d->check += 20000;
}

static char	*fill(char *str, char *s1, int x, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		str[i] = s1[x];
		i++;
		x++;
	}
	str[i] = '\0';
	return (str);
}

char		*path(t_flags *d, char *s1, char c)
{
	char	*str;
	int		len;
	int		i;

	i = 2;
	if (c == 'O')
		i = 1;
	len = 0;
	while (s1[i] == 32 || (s1[i] == 9 || s1[i] == '.' ||
		s1[i] == '/'))
		i++;
	while (s1[i + len] != '\n')
		len++;
	d->i = d->i + i + len + 1;
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!str)
		return (NULL);
	str = fill(str, s1, i, len);
	check(d, c);
	return (str);
}
