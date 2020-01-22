/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_result_colors.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 15:11:54 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 17:54:21 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_ceiling(t_flags *data)
{
	char	*tmp;

	data->ceiling = 0;
	tmp = ft_strdup((char *)data->c);
	free(data->c);
	data->c = ft_split(tmp, ',');
	free(tmp);
	data->cred = ft_atoi(data->c[0]);
	data->cgreen = ft_atoi(data->c[1]);
	data->cblue = ft_atoi(data->c[2]);
	data->ceiling = data->ceiling + data->cblue % 16;
	data->ceiling = data->ceiling + data->cblue / 16 * 16;
	data->ceiling = data->ceiling + data->cgreen % 16 * pow(16, 2);
	data->ceiling = data->ceiling + data->cgreen / 16 * pow(16, 3);
	data->ceiling = data->ceiling + data->cred % 16 * pow(16, 4);
	data->ceiling = data->ceiling + data->cred / 16 * pow(16, 5);
	if (data->ceiling < 0)
		return (0);
	return (1);
}

int		ft_floor(t_flags *data)
{
	char	*tmp;

	data->floor = 0;
	tmp = ft_strdup((char *)data->f);
	free(data->f);
	data->f = ft_split(tmp, ',');
	free(tmp);
	data->fred = ft_atoi(data->f[0]);
	data->fgreen = ft_atoi(data->f[1]);
	data->fblue = ft_atoi(data->f[2]);
	data->floor = data->floor + data->fblue % 16;
	data->floor = data->floor + data->fblue / 16 * 16;
	data->floor = data->floor + data->fgreen % 16 * pow(16, 2);
	data->floor = data->floor + data->fgreen / 16 * pow(16, 3);
	data->floor = data->floor + data->fred % 16 * pow(16, 4);
	data->floor = data->floor + data->fred / 16 * pow(16, 5);
	if (data->floor < 0)
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

int		ft_result_colors(t_flags *data)
{
	if (ft_result(data) == 0)
		return (0);
	if (ft_floor(data) == 0)
		return (0);
	if (ft_ceiling(data) == 0)
		return (0);
	return (1);
}
