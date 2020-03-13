/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_result_colors.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 14:05:13 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_color(t_flags *d, t_color *color, char c)
{
	if (c == 'c')
	{
		CRED = ft_atoi(CSTR[0]);
		if (CRED > 255 || CRED < 0)
			ERROR = "CEILING RED NOT CORRECT\n";
		CGREEN = ft_atoi(CSTR[1]);
		if (CGREEN > 255 || CGREEN < 0)
			ERROR = "CEILING GREEN NOT CORRECT\n";
		CBLUE = ft_atoi(CSTR[2]);
		if (CBLUE > 255 || CBLUE < 0)
			ERROR = "CEILING BLUE NOT CORRECT\n";
		if (ERROR != NULL)
			return (0);
	}
	else
	{
		FRED = ft_atoi(FSTR[0]);
		if (FRED > 255 || FRED < 0)
			ERROR = "FLOOR RED NOT CORRECT\n";
		FGREEN = ft_atoi(FSTR[1]);
		if (FGREEN > 255 || FGREEN < 0)
			ERROR = "FLOOR GREEN NOT CORRECT\n";
		FBLUE = ft_atoi(FSTR[2]);
		if (FBLUE > 255 || FBLUE < 0)
			ERROR = "FLOOR BLUE NOT CORRECT\n";
		if (ERROR != NULL)
			return (0);
	}
	return (1);
}

int		ft_ceiling(t_flags *d, t_color *color)
{
	char	*tmp;

	CEILING = 0;
	tmp = ft_strdup((char *)CSTR);
	free(CSTR);
	CSTR = ft_split(tmp, ',');
	free(tmp);
	if (check_color(d, color, 'c') == 0)
		return (0);
	CEILING = CEILING + CBLUE % 16;
	CEILING = CEILING + CBLUE / 16 * 16;
	CEILING = CEILING + CGREEN % 16 * pow(16, 2);
	CEILING = CEILING + CGREEN / 16 * pow(16, 3);
	CEILING = CEILING + CRED % 16 * pow(16, 4);
	CEILING = CEILING + CRED / 16 * pow(16, 5);
	if (CEILING < 0)
		return (0);
	return (1);
}

int		ft_floor(t_flags *d, t_color *color)
{
	char	*tmp;

	FLOOR = 0;
	tmp = ft_strdup((char *)FSTR);
	free(FSTR);
	FSTR = ft_split(tmp, ',');
	free(tmp);
	if (check_color(d, color, 'f') == 0)
		return (0);
	FLOOR = FLOOR + FBLUE % 16;
	FLOOR = FLOOR + FBLUE / 16 * 16;
	FLOOR = FLOOR + FGREEN % 16 * pow(16, 2);
	FLOOR = FLOOR + FGREEN / 16 * pow(16, 3);
	FLOOR = FLOOR + FRED % 16 * pow(16, 4);
	FLOOR = FLOOR + FRED / 16 * pow(16, 5);
	if (FLOOR < 0)
		return (0);
	return (1);
}

int		ft_result(t_flags *d)
{
	char	*tmp;

	tmp = ft_strdup((char *)d->r);
	free(d->r);
	d->r = ft_split(tmp, ' ');
	free(tmp);
	RESX = ft_atoi(d->r[0]);
	RESY = ft_atoi(d->r[1]);
	if (RESX <= 0 || RESY <= 0)
		return (0);
	if (RESX < 200)
		RESX = 200;
	if (RESY < 200)
		RESY = 200;
	return (1);
}

int		ft_result_colors(t_flags *d, t_color *color)
{
	if (ft_result(d) == 0)
		return (0);
	if (ft_floor(d, color) == 0)
		return (0);
	if (ft_ceiling(d, color) == 0)
		return (0);
	return (1);
}
