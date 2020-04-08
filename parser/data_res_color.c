/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_res_color.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:00:25 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:46:15 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	between(char *str, int *index)
{
	int	i;

	i = *index;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != ',')
		return (0);
	i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	*index = i;
	return (1);
}

void		data_ceiling(t_flags *d, char *str)
{
	int i;

	i = 0;
	ERROR = "CEILING COLOR ISN'T CORRECT\n";
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	CRED = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	CGREEN = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	CBLUE = ft_atoi(&str[i]);
	if (CRED > 255 || CGREEN > 255 || CBLUE < 0 || CBLUE > 255)
		return ;
	CHECK += 2000000;
	ERROR = "";
}

void		data_floor(t_flags *d, char *str)
{
	int	i;

	i = 0;
	ERROR = "FLOOR COLOR ISN'T CORRECT\n";
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	FRED = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	FGREEN = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	FBLUE = ft_atoi(&str[i]);
	if (FRED > 255 || FGREEN > 255 || FBLUE < 0 || FBLUE > 255)
		return ;
	CHECK += 400000;
	ERROR = "";
}

void		resolution(t_flags *d, char *str)
{
	int i;

	i = 0;
	ERROR = "RESOLUTION IS NOT CORRECT\n";
	RESX = ft_atoi(str);
	if (RESX < 0 || RESX > 100000)
		return ;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	RESY = ft_atoi(&str[i]);
	if (RESY < 0 || RESY < 0)
		return ;
	if (RESX < 25)
		RESX = 25;
	if (RESY < 25)
		RESY = 25;
	CHECK += 40000000;
	ERROR = "";
}
