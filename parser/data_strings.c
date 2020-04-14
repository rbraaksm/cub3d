/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_strings.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:37:22 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 13:42:18 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north(t_flags *d, const char *s1, char c, int *index)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	while (s1[i + len] != c)
		len++;
	*index = *index + i + len + 1;
	d->no = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!d->no)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		d->no[i] = s1[x];
		i++;
		x++;
	}
	d->no[i] = '\0';
	d->check += 2;
}

void	east(t_flags *d, const char *s1, char c, int *index)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	while (s1[i + len] != c)
		len++;
	*index = *index + i + len + 1;
	d->ea = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!d->ea)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		d->ea[i] = s1[x];
		i++;
		x++;
	}
	d->ea[i] = '\0';
	d->check += 40;
}

void	south(t_flags *d, const char *s1, char c, int *index)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	while (s1[i + len] != c)
		len++;
	*index = *index + i + len + 1;
	d->so = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!d->so)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		d->so[i] = s1[x];
		i++;
		x++;
	}
	d->so[i] = '\0';
	d->check += 200;
}

void	west(t_flags *d, const char *s1, char c, int *index)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	while (s1[i + len] != c)
		len++;
	*index = *index + i + len + 1;
	d->we = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!d->we)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		d->we[i] = s1[x];
		i++;
		x++;
	}
	d->we[i] = '\0';
	d->check += 4000;
}

void	sprite(t_flags *d, const char *s1, char c, int *index)
{
	int		len;
	int		i;
	int		x;

	i = 1;
	len = 0;
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	while (s1[i + len] != c)
		len++;
	*index = *index + i + len + 1;
	d->s = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!d->s)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		d->s[i] = s1[x];
		i++;
		x++;
	}
	d->s[i] = '\0';
	d->check += 20000;
}
