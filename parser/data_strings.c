/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_strings.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 10:37:22 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 14:35:26 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	north(t_flags *d, const char *s1, char c)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == ' ')
		i++;
	while (s1[i + len] != c)
		len++;
	NORTH = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!NORTH)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		NORTH[i] = s1[x];
		i++;
		x++;
	}
	NORTH[i] = '\0';
	CHECK += 2;
}

void	east(t_flags *d, const char *s1, char c)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == ' ')
		i++;
	while (s1[i + len] != c)
		len++;
	EAST = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!EAST)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		EAST[i] = s1[x];
		i++;
		x++;
	}
	EAST[i] = '\0';
	CHECK += 40;
}

void	south(t_flags *d, const char *s1, char c)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == ' ')
		i++;
	while (s1[i + len] != c)
		len++;
	SOUTH = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!SOUTH)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		SOUTH[i] = s1[x];
		i++;
		x++;
	}
	SOUTH[i] = '\0';
	CHECK += 200;
}

void	west(t_flags *d, const char *s1, char c)
{
	int		len;
	int		i;
	int		x;

	i = 2;
	len = 0;
	while (s1[i] == ' ')
		i++;
	while (s1[i + len] != c)
		len++;
	WEST = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!WEST)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		WEST[i] = s1[x];
		i++;
		x++;
	}
	WEST[i] = '\0';
	CHECK += 4000;
}

void	sprite(t_flags *d, const char *s1, char c)
{
	int		len;
	int		i;
	int		x;

	i = 1;
	len = 0;
	while (s1[i] == ' ')
		i++;
	while (s1[i + len] != c)
		len++;
	SPRITE = (char *)malloc(sizeof(*s1) * (len + 1));
	if (!SPRITE)
		return ;
	x = i;
	i = 0;
	while (i < len)
	{
		SPRITE[i] = s1[x];
		i++;
		x++;
	}
	SPRITE[i] = '\0';
	CHECK += 20000;
}
