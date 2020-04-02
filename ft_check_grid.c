/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_check_grid.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:20:09 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/04/02 16:02:50 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int  first_line(t_flags *d)
{
    int i;

    i = 0;
    ERROR = "FIRST LINE ISN'T CORRECT\n";
    while (i < ft_strlen(MAP[0]))
    {
        if (MAP[0][i] == '1')
            i++;
        else if (MAP[0][i] == ' ' && (MAP[1][i] == ' ' || MAP[1][i] == '1'))
            i++;
        else
            return (0);
    }
    ERROR = "";
    return (1);
}

static int  middle_lines_2(t_flags *d, int y, int i)
{
    while (i < ft_strlen(MAP[y]))
	{
        if (ft_strchr(d, MAP[y][i], y, i) == 1)
            i++;
        else if (MAP[y][i] == ' ')
		{
			if (i < ft_strlen(MAP[y - 1]) && !(MAP[y - 1][i] == ' ' || MAP[y - 1][i] == '1'))
				return (0);
			if (i < ft_strlen(MAP[y + 1]) && !(MAP[y + 1][i] == ' ' || MAP[y + 1][i] == '1'))
				return (0);
			if (i != 0 && !(MAP[y][i - 1] == ' ' || MAP[y][i - 1] == '1'))
				return (0);
			if (i + 1 != ft_strlen(MAP[y]) && !(MAP[y][i + 1] == ' ' || MAP[y][i + 1] == '1'))
				return (0);
			i++;
		}
		else
			return (0);
	}
   printf("Y: %d is correct\n", y);
    ERROR = "";
	return (1);
}

static int  middle_lines(t_flags *d, int y)
{
    int i;

    i = 0;
    ERROR = "MAP ISN'T CORRECT\n";
    while (MAP[y][i] == ' ')
        i++;
    if (MAP[y][i] != '1')
        return (0);
    i = 0;
    if (middle_lines_2(d, y, i) == 0)
        return (0);
    i = ft_strlen(MAP[y]) - 1;
    while (MAP[y][i] == ' ')
        i--;
    if (MAP[y][i] != '1')
        return (0);
    ERROR = "";
    return (1);
}

static int   last_line(t_flags *d, int y)
{
	int	x;

	x = 0;
    ERROR = "LAST LINE ISN'T CORRECT\n";
    while (MAP[y][x] != '\0')
    {
        if (MAP[y][x] == '1')
            x++;
        else if (MAP[y][x] == ' ' && (MAP[y - 1][x] == ' ' || MAP[y - 1][x] == '1'))
            x++;
        else
            return (0);
    }
    ERROR = "";
	return (1);
}

int		check_grid(t_flags *d)
{
	int		i;

	i = 0;
    while (i < ROW_C)
    {
        if (i == 0)
            if (first_line(d) == 0)
                return (0);
        if (i > 0 && i < ROW_C - 1)
            if (middle_lines(d, i) == 0)
                return (0);
        if (i == ROW_C - 1)
            if (last_line(d, i) == 0)
                return (0);
        i++;
    }
    if (PLAY_X == 0 || PLAY_Y == 0)
    {
        ERROR = "NO PLAYER IN THE MAP\n";
        return (0);
    }
	return (1);
}
