/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fill_grid.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/04/01 17:58:09 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_location(t_flags *d, int column, char c)
{
	printf("test\n");
	if (PLAY_X == 0 && PLAY_Y == 0)
	{
		PLAY_X = column + 0.5;
		PLAY_Y = ROW_I + 0.5;
		POS = c;
	}
	else
	{
		ERROR = "TO MANY PLAYERS IN THE MAP\n";
		return (0);
	}
	return (1);

}

int		ft_strchr(t_flags *d, char c, int column)
{
	char	*s1;
	int		i;

	s1 = " 012NWSE";
	i = 0;
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		if (set_location(d, column, c) == 0)
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
	MAP[ROW_I] = (char *)malloc(sizeof(char *) * (column + 1));
	if (MAP[ROW_I] == NULL)
		return (0);
	while (i < column)
	{
		if (ft_strchr(d, STR[start + i], i) == 1)
			MAP[ROW_I][i] = STR[start + i];
		else
			return (0);
		i++;
	}
	MAP[ROW_I][i] = '\0';
	return (1);
}

int		find_start(t_flags *d, int end)
{
	ROW_C = 1;
	while (STR[end] == '1' || STR[end] == '2' || STR[end] == ' ' ||
			STR[end] == '0' || STR[end] == '\n' || STR[end] == 'N' ||
			STR[end] == 'E' || STR[end] == 'S' || STR[end] == 'W')
	{
		if (STR[end] == '\n' && STR[end - 1] == '\n')
			break ;
		if (STR[end] == '\n')
			ROW_C++;
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
	printf("POSITION: %c\n", POS);
	return (1);
}
