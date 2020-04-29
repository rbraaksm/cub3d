/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_res_color.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 11:00:25 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/29 16:27:19 by rbraaksm      ########   odam.nl         */
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

void		data_ceiling(t_vars *v, char *str)
{
	int i;

	i = 0;
	v->error = "ERROR\nCEILING COLOR ISN'T CORRECT\n";
	while (str[i] != '\n')
		i++;
	v->i = v->i + i + 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	v->cred = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	v->cgreen = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	v->cblue = ft_atoi(&str[i]);
	if (v->cred > 255 || v->cgreen > 255 || v->cblue < 0 || v->cblue > 255)
		return ;
	if (color_between_end(str, &i, 'E') == 0)
		return ;
	v->check += 2000000;
	v->error = "";
}

void		data_floor(t_vars *v, char *str)
{
	int	i;

	i = 0;
	v->error = "ERROR\nFLOOR COLOR ISN'T CORRECT\n";
	while (str[i] != '\n')
		i++;
	v->i = v->i + i + 2;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	v->fred = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	v->fgreen = ft_atoi(&str[i]);
	if (color_between_end(str, &i, 'B') == 0)
		return ;
	v->fblue = ft_atoi(&str[i]);
	if (v->fred > 255 || v->fgreen > 255 || v->fblue < 0 || v->fblue > 255)
		return ;
	if (color_between_end(str, &i, 'E') == 0)
		return ;
	v->check += 400000;
	v->error = "";
}

static int	check_resolution(t_vars *v, char *str, int *index, char c)
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
	if (v->resx > 16384 || v->resy > 16384 || v->resx == 0 || v->resy == 0)
		return (0);
	return (1);
}

void		resolution(t_vars *v, char *str)
{
	int i;

	i = 1;
	v->error = "ERROR\nRESOLUTION IS NOT CORRECT\n";
	while (str[i] != '\n')
		i++;
	v->i = v->i + i;
	i = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return ;
	v->resx = ft_atoi(&str[i]);
	if (check_resolution(v, str, &i, 'B') == 0)
		return ;
	v->resy = ft_atoi(&str[i]);
	if (check_resolution(v, str, &i, 'E') == 0)
		return ;
	v->check += 40000000;
	v->error = "";
}
