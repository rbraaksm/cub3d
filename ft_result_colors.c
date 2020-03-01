/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_result_colors.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/27 15:18:02 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_string(t_flags *d)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < 2)
	{
		count = 0;
		while (d->f[i][count] != '\0')
		{
			if (d->f[i][count] >= '0' || d->f[i][count] <= '9')
				return (1);
			count++;
		}
		i++;
	}
	d->error = "FLOOR COLOR IS NOT CORRECT\n";
	return (0);
}

int		check_color(t_flags *d, t_color *color, char c)
{
	if (c == 'c')
	{
		color->cred = ft_atoi(d->c[0]);
		if (color->cred > 255 || color->cred < 0)
			d->error = "CEILING RED NOT CORRECT\n";
		color->cgreen = ft_atoi(d->c[1]);
		if (color->cgreen > 255 || color->cgreen < 0)
			d->error = "CEILING GREEN NOT CORRECT\n";
		color->cblue = ft_atoi(d->c[2]);
		if (color->cblue > 255 || color->cblue < 0)
			d->error = "CEILING BLUE NOT CORRECT\n";
		if (d->error != NULL)
			return (0);
	}
	else
	{
		color->fred = ft_atoi(d->f[0]);
		if (color->fred > 255 || color->fred < 0)
			d->error = "FLOOR RED NOT CORRECT\n";
		color->fgreen = ft_atoi(d->f[1]);
		if (color->fgreen > 255 || color->fgreen < 0)
			d->error = "FLOOR GREEN NOT CORRECT\n";
		color->fblue = ft_atoi(d->f[2]);
		if (color->fblue > 255 || color->fblue < 0)
			d->error = "FLOOR BLUE NOT CORRECT\n";
		if (d->error != NULL)
			return (0);
	}
	return (1);
}

int		ft_ceiling(t_flags *d, t_color *color)
{
	char	*tmp;

	color->ceiling = 0;
	tmp = ft_strdup((char *)d->c);
	free(d->c);
	d->c = ft_split(tmp, ',');
	free(tmp);
	if (check_color(d, color, 'c') == 0)
		return (0);
	color->ceiling = color->ceiling + color->cblue % 16;
	color->ceiling = color->ceiling + color->cblue / 16 * 16;
	color->ceiling = color->ceiling + color->cgreen % 16 * pow(16, 2);
	color->ceiling = color->ceiling + color->cgreen / 16 * pow(16, 3);
	color->ceiling = color->ceiling + color->cred % 16 * pow(16, 4);
	color->ceiling = color->ceiling + color->cred / 16 * pow(16, 5);
	if (color->ceiling < 0)
		return (0);
	return (1);
}

int		ft_floor(t_flags *d, t_color *color)
{
	char	*tmp;

	color->floor = 0;
	tmp = ft_strdup((char *)d->f);
	free(d->f);
	d->f = ft_split(tmp, ',');
	free(tmp);
	// if (check_string(d) == 0)
	// 	return (0);
	if (check_color(d, color, 'f') == 0)
		return (0);
	color->floor = color->floor + color->fblue % 16;
	color->floor = color->floor + color->fblue / 16 * 16;
	color->floor = color->floor + color->fgreen % 16 * pow(16, 2);
	color->floor = color->floor + color->fgreen / 16 * pow(16, 3);
	color->floor = color->floor + color->fred % 16 * pow(16, 4);
	color->floor = color->floor + color->fred / 16 * pow(16, 5);
	if (color->floor < 0)
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
	d->resx = ft_atoi(d->r[0]);
	d->resy = ft_atoi(d->r[1]);
	if (d->resx <= 0 || d->resy <= 0)
		return (0);
	if (d->resx < 200)
		d->resx = 200;
	if (d->resy < 200)
		d->resy = 200;
	return (1);
}

int		ft_result_colors(t_flags *d, t_color *color)
{
	// if (d->error != NULL)
	// 	return (0);
	if (ft_result(d) == 0)
		return (0);
	if (ft_floor(d, color) == 0)
		return (0);
	if (ft_ceiling(d, color) == 0)
		return (0);
	return (1);
}
