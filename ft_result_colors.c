/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_result_colors.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/20 11:32:35 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ceiling(t_flags *data, t_color *color)
{
	char	*tmp;

	color->ceiling = 0;
	tmp = ft_strdup((char *)data->c);
	free(data->c);
	data->c = ft_split(tmp, ',');
	free(tmp);
	color->cred = ft_atoi(data->c[0]);
	color->cgreen = ft_atoi(data->c[1]);
	color->cblue = ft_atoi(data->c[2]);
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

int		ft_floor(t_flags *data, t_color *color)
{
	char	*tmp;

	color->floor = 0;
	tmp = ft_strdup((char *)data->f);
	free(data->f);
	data->f = ft_split(tmp, ',');
	free(tmp);
	color->fred = ft_atoi(data->f[0]);
	color->fgreen = ft_atoi(data->f[1]);
	color->fblue = ft_atoi(data->f[2]);
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

int		ft_result(t_flags *data)
{
	char	*tmp;

	tmp = ft_strdup((char *)data->r);
	free(data->r);
	data->r = ft_split(tmp, ' ');
	free(tmp);
	data->resx = ft_atoi(data->r[0]);
	data->resy = ft_atoi(data->r[1]);
	if (data->resx <= 0 || data->resy <= 0)
		return (0);
	return (1);
}

int		ft_result_colors(t_flags *data, t_color *color)
{
	if (ft_result(data) == 0)
		return (0);
	if (ft_floor(data, color) == 0)
		return (0);
	if (ft_ceiling(data, color) == 0)
		return (0);
	return (1);
}
