/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_strings.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:37:22 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/21 15:53:33 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check(t_vars *v, char c)
{
	if (c == 'N')
		v->check += 2;
	else if (c == 'E')
		v->check += 40;
	else if (c == 'S')
		v->check += 200;
	else if (c == 'W')
		v->check += 4000;
	else if (c == 'O')
		v->check += 20000;
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

char		*path(t_vars *v, char *s1, char c)
{
	char	*str;
	int		len;
	int		i;

	v->error = "ERROR: INDEX ISN'T CORRECT\n";
	i = 2;
	len = 0;
	while (s1[i] == 32 || (s1[i] == 9 || s1[i] == '.' ||
		s1[i] == '/'))
		i++;
	while (s1[i + len] != '\n')
		len++;
	v->i = v->i + i + len + 1;
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!str)
		return (NULL);
	str = fill(str, s1, i, len);
	check(v, c);
	v->error = "";
	return (str);
}
