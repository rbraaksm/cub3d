/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 12:49:36 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				error_check(t_vars *v, char *str)
{
	int	i;

	i = 0;
	while (v->error[i] != '\0')
	{
		if (v->error[i] != str[i])
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

static int		set_location(t_vars *v, int row, int column, char c)
{
	if (v->player.x == 0 && v->player.y == 0)
	{
		v->player.x = column + 0.5;
		v->player.y = row + 0.5;
		if (c == 'N')
			v->ray.playdir = M_PI;
		else if (c == 'E')
			v->ray.playdir = M_PI * 0.5;
		else if (c == 'S')
			v->ray.playdir = 0;
		else if (c == 'W')
			v->ray.playdir = M_PI * 1.5;
	}
	else
	{
		v->error = "ERROR\nTO MANY PLAYERS IN THE MAP\n";
		return (0);
	}
	return (1);
}

int				ft_strchr(t_vars *v, char c, int row, int column)
{
	char	*s1;
	int		i;

	v->error = "ERROR\nWRONG CHARACTER\n";
	s1 = "012NWSE";
	i = 0;
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		if (set_location(v, row, column, c) == 0)
			return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}
