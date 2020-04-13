/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_parser.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 17:36:02 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/13 17:28:15 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_str(t_flags *d, int *i)
{
	if (STR[*i] == ' ' || STR[*i] == '1' || STR[*i] == '2' ||
		STR[*i] == '0' || STR[*i] == '\n')
		*i = *i + 1;
	else if ((STR[*i] == 'N' || STR[*i] == 'E' || STR[*i] == 'S' ||
			STR[*i] == 'W') && (STR[*i + 1] != '1' || STR[*i + 1] != '2' ||
			STR[*i + 1] != '0'))
		ERROR = "INDEX ISN'T CORRECT\n";
	else
		ERROR = "INDEX ISN'T CORRECT\n";
}

static void	find_values(t_flags *d)
{
	int	index;

	index = 0;
	while (STR[index] != '\0' && error_check(d, "") == 1)
	{
		if (STR[index] == 'R')
			resolution(d, &(STR)[index + 1], &index);
		else if (STR[index] == 'N' && STR[index + 1] == 'O' && !NORTH)
			north(d, &(STR)[index], '\n', &index);
		else if (STR[index] == 'S' && STR[index + 1] == 'O' && !SOUTH)
			south(d, &(STR[index]), '\n', &index);
		else if (STR[index] == 'W' && STR[index + 1] == 'E' && !WEST)
			west(d, &(STR)[index], '\n', &index);
		else if (STR[index] == 'E' && STR[index + 1] == 'A' && !EAST)
			east(d, &(STR)[index], '\n', &index);
		else if (STR[index] == 'S' && STR[index + 1] != 'O' && !SPRITE)
			sprite(d, &(STR)[index], '\n', &index);
		else if (STR[index] == 'F')
			data_floor(d, &(STR)[index + 1], &index);
		else if (STR[index] == 'C')
			data_ceiling(d, &(STR)[index + 1], &index);
		else
			check_str(d, &index);
	}
}

static void	colors(t_flags *d)
{
	CEILING = CEILING + CBLUE % 16;
	CEILING = CEILING + CBLUE / 16 * 16;
	CEILING = CEILING + CGREEN % 16 * pow(16, 2);
	CEILING = CEILING + CGREEN / 16 * pow(16, 3);
	CEILING = CEILING + CRED % 16 * pow(16, 4);
	CEILING = CEILING + CRED / 16 * pow(16, 5);
	FLOOR = FLOOR + FBLUE % 16;
	FLOOR = FLOOR + FBLUE / 16 * 16;
	FLOOR = FLOOR + FGREEN % 16 * pow(16, 2);
	FLOOR = FLOOR + FGREEN / 16 * pow(16, 3);
	FLOOR = FLOOR + FRED % 16 * pow(16, 4);
	FLOOR = FLOOR + FRED / 16 * pow(16, 5);
}

static void	set_values(t_flags *d)
{
	CHECK = 0;
	RESX = 0;
	RESY = 0;
	FRED = -1;
	FGREEN = -1;
	FBLUE = -1;
	CRED = -1;
	CGREEN = -1;
	CBLUE = -1;
	CEILING = 0;
	FLOOR = 0;
	ERROR = "";
	NORTH = NULL;
	EAST = NULL;
	SOUTH = NULL;
	WEST = NULL;
	SPRITE = NULL;
}

int			fill_parser(t_flags *d)
{
	set_values(d);
	find_values(d);
	if (CHECK != 42424242)
		return (0);
	colors(d);
	return (1);
}
