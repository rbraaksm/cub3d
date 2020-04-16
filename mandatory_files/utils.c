/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/16 10:59:31 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				error_check(t_flags *d, char *str)
{
	int	i;

	i = 0;
	while (d->error[i] != '\0')
	{
		if (d->error[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

static long int	check(const char *str, int i, unsigned long int res, int sign)
{
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (res >= 922337203685477580 && ((str[i] - '0') > 7) && sign == 1)
			return (-1);
		else if (res >= 922337203685477580
					&& ((str[i] - '0') > 8) && sign == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	result = 0;
	sign = 1;
	if (!str[i])
		return (0);
	while (str[i] != '\0' && (str[i] == 32 || (str[i] > 8 && str[i] < 14)))
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		sign = -1;
		i++;
	}
	result = check(str, i, result, sign);
	result = result * sign;
	return (result);
}

static int		set_location(t_flags *d, int row, int column, char c)
{
	if (d->play_x == 0 && d->play_y == 0)
	{
		d->play_x = column + 0.5;
		d->play_y = row + 0.5;
		d->position = c;
	}
	else
	{
		d->error = "ERROR: TO MANY PLAYERS IN THE MAP\n";
		return (0);
	}
	return (1);
}

int				ft_strchr(t_flags *d, char c, int row, int column)
{
	char	*s1;
	int		i;

	d->error = "ERROR: WRONG CHARACTER\n";
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
