/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 15:00:49 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		set_location(t_flags *d, int row, int column, char c)
{
	if (PLAY_X == 0 && PLAY_Y == 0)
	{
		PLAY_X = column + 0.5;
		PLAY_Y = row + 0.5;
		POS = c;
	}
	else
	{
		ERROR = "TO MANY PLAYERS IN THE MAP\n";
		return (0);
	}
	return (1);
}

int		ft_strchr(t_flags *d, char c, int row, int column)
{
	char	*s1;
	int		i;

	s1 = "012NWSE";
	i = 0;
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		if (set_location(d, row, column, c) == 0)
			return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		fill_row(t_flags *d, int column, int start)
{
	int	i;

	i = 0;
	MAP[ROW_I] = (char *)malloc(sizeof(char *) * (COLUMN + 1));
	if (MAP[ROW_I] == NULL)
		return (0);
	while (i < COLUMN)
	{
		MAP[ROW_I][i] = ' ';
		i++;
	}
	MAP[ROW_I][i] = '\0';
	i = 0;
	while (i < column)
	{
		MAP[ROW_I][i] = STR[start + i];
		i++;
	}
	return (1);
}

int		find_start(t_flags *d, int end)
{
	int	c;

	c = 0;
	COLUMN = 0;
	ROW_C = 1;
	while (STR[end] == '1' || STR[end] == '2' || STR[end] == ' ' ||
			STR[end] == '0' || STR[end] == '\n' || STR[end] == 'N' ||
			STR[end] == 'E' || STR[end] == 'S' || STR[end] == 'W')
	{
		c++;
		if (STR[end] == '\n' && STR[end - 1] == '\n')
			break ;
		if (STR[end] == '\n')
		{
			if (c > COLUMN)
				COLUMN = c;
			ROW_C++;
			c = 0;
		}
		end--;
	}
	while (STR[end] != '\n')
		end++;
	return (end + 1);
}

int		fill_grid(t_flags *d)
{
	int		start;
	int		end;
	int		c;

	ROW_I = 0;
	PLAY_X = 0;
	PLAY_Y = 0;
	end = ft_strlen(STR) - 1;
	start = find_start(d, end);
	MAP = (char **)malloc(sizeof(char *) * (ROW_C));
	if (MAP == NULL)
		return (0);
	while (ROW_I < ROW_C)
	{
		c = 0;
		while (STR[c + start] != '\n' && STR[c + start] != '\0')
			c++;
		if (fill_row(d, c, start) == 0)
			return (0);
		start = start + c + 1;
		ROW_I++;
	}
	return (1);
}
