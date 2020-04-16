/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_res_color.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:00:25 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/16 10:45:17 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	color_between_end(char *str, int *index, char c)
{
	while (str[*index] >= '0' && str[*index] <= '9')
		*index = *index + 1;
	while (str[*index] == 32 || str[*index] == 9)
		*index = *index + 1;
	if (c == 'B')
		if (str[*index] != ',')
			return (0);
	if (c == 'E')
	{
		if (str[*index] == '\n')
			return (1);
		else
			return (0);
	}
	*index = *index + 1;
	while (str[*index] == 32 || str[*index] == 9)
		*index = *index + 1;
	if (str[*index] < '0' || str[*index] > '9')
		return (0);
	return (1);
}

void		data_ceiling(t_flags *d, char *str)
{
	int i;

	i = 0;
	d->error = "ERROR: CEILING COLOR ISN'T CORRECT\n";
	while (str[i] != '\n')
		i++;
	d->i = d->i + i + 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	d->cred = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	d->cgreen = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	d->cblue = ft_atoi(&str[i]);
	if (d->cred > 255 || d->cgreen > 255 || d->cblue < 0 || d->cblue > 255)
		return ;
	if (color_between_end(str, &i, 'E') == 0)
		return ;
	d->check += 2000000;
	d->error = "";
}

void		data_floor(t_flags *d, char *str)
{
	int	i;

	i = 0;
	d->error = "ERROR: FLOOR COLOR ISN'T CORRECT\n";
	while (str[i] != '\n')
		i++;
	d->i = d->i + i + 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	d->fred = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	d->fgreen = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	d->fblue = ft_atoi(&str[i]);
	if (d->fred > 255 || d->fgreen > 255 || d->fblue < 0 || d->fblue > 255)
		return ;
	if (color_between_end(str, &i, 'E') == 0)
		return ;
	d->check += 400000;
	d->error = "";
}

static int	check_resolution(t_flags *d, char *str, int *index, char c)
{
	if (str[*index] < '0' || str[*index] > '9')
		return (0);
	if (c == 'B')
	{
		while (str[*index] >= '0' && str[*index] <= '9')
			*index = *index + 1;
		while (str[*index] == 32 || str[*index] == 9)
			*index = *index + 1;
		return (1);
	}
	while (str[*index] >= '0' && str[*index] <= '9')
		*index = *index + 1;
	while (str[*index] == 32 || str[*index] == 9)
		*index = *index + 1;
	if (str[*index] != '\n')
		return (0);
	if (d->resx < 25 || d->resy < 25)
		write(1, "PLEASE KEEP RESOLUTION ABOVE 25\n", 32);
	if (d->resx < 25)
		d->resx = 25;
	if (d->resy < 25)
		d->resy = 25;
	return (1);
}

void		resolution(t_flags *d, char *str)
{
	int i;

	i = 0;
	d->error = "ERROR: RESOLUTION IS NOT CORRECT\n";
	while (str[d->i] != '\n')
		d->i++;
	d->i += 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	d->resx = ft_atoi(&str[i]);
	if (check_resolution(d, str, &i, 'B') == 0)
		return ;
	d->resy = ft_atoi(&str[i]);
	if (check_resolution(d, str, &i, 'E') == 0)
		return ;
	d->check += 40000000;
	d->error = "";
}
