/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_res_color.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:00:25 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 12:35:33 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	between(char *str, int *index)
{
	int	i;

	i = *index;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	if (str[i] != ',')
		return (0);
	i++;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	*index = i;
	return (1);
}

void		data_ceiling(t_flags *d, char *str, int *index)
{
	int i;

	i = 0;
	d->error = "ERROR: CEILING COLOR ISN'T CORRECT\n";
	while (str[i] != '\n')
		i++;
	*index = *index + i + 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	d->cred = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	d->cgreen = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	d->cblue = ft_atoi(&str[i]);
	if (d->cred > 255 || d->cgreen > 255 || d->cblue < 0 || d->cblue > 255)
		return ;
	d->check += 2000000;
	d->error = "";
}

void		data_floor(t_flags *d, char *str, int *index)
{
	int	i;

	i = 0;
	d->error = "ERROR: FLOOR COLOR ISN'T CORRECT\n";
	while (str[i] != '\n')
		i++;
	*index = *index + i + 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	d->fred = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	d->fgreen = ft_atoi(&str[i]);
	if (between(str, &i) == 0)
		return ;
	d->fblue = ft_atoi(&str[i]);
	if (d->fred > 255 || d->fgreen > 255 || d->fblue < 0 || d->fblue > 255)
		return ;
	d->check += 400000;
	d->error = "";
}

void		resolution(t_flags *d, char *str, int *index)
{
	int i;

	i = 0;
	d->error = "ERROR: RESOLUTION IS NOT CORRECT\n";
	while (str[i] != '\n')
		i++;
	*index = *index + i + 2;
	i = 0;
	d->resx = ft_atoi(str);
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	d->resy = ft_atoi(&str[i]);
	if (d->resy < 0 || d->resx < 0)
		return ;
	if (d->resx < 25 || d->resy < 25)
		write(1, "PLEASE KEEP RESOLUTION ABOVE 25\n", 32);
	if (d->resx < 25)
		d->resx = 25;
	if (d->resy < 25)
		d->resy = 25;
	d->check += 40000000;
	d->error = "";
}
