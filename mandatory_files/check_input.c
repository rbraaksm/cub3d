/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 09:57:00 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 09:47:07 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_strcmp(char *arg, char *s1, t_vars *v, char c)
{
	int i;
	int	i2;

	i = 0;
	while (arg[i] != 0)
		i++;
	i--;
	if (c == 'C')
		i2 = 3;
	else
		i2 = 5;
	while (i2 >= 0)
	{
		if (arg[i] != s1[i2])
		{
			if (c == 'C')
				v->error = "ERROR\nIT'S NOT A .CUB FILE\n";
			else if (c == 'S')
				v->error = "ERROR\nDID YOU MEAN --SAVE?\n";
			return (0);
		}
		i--;
		i2--;
	}
	return (1);
}

int			check_input(int argc, char **argv, t_vars *v)
{
	if (argc < 2 || argc > 3)
	{
		v->error = "ERROR\nCHECK ARGUMENTS\n";
		return (0);
	}
	if (ft_strcmp(argv[1], ".cub", v, 'C') == 0)
		return (0);
	if (argc == 3 && ft_strcmp(argv[2], "--save", v, 'S') == 0)
		return (0);
	if (argc == 3)
		v->save = 1;
	return (1);
}
