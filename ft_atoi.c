/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 09:59:44 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
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
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		sign = -1;
		i++;
	}
	result = check(str, i, result, sign);
	result = result * sign;
	return (result);
}
