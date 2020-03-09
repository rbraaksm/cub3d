/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/09 13:44:24 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		argv_check(char *argv, t_flags *d)
{
	int		i;

	d->error = "IT'S NOT A .CUB FILE\n";
	i = ft_strlen(argv);
	if (argv[i - 1] != 'b')
		return (0);
	if (argv[i - 2] != 'u')
		return (0);
	if (argv[i - 3] != 'c')
		return (0);
	if (argv[i - 4] != '.')
		return (0);
	d->error = NULL;
	return (1);
	
}

int		check_map(char **argv, t_flags *d, t_color *color, t_map *map)
{
	if (argv_check(argv[1], d) == 0)
		return(0);
	if (make_string(argv, d) == 0)
		return (0);
	if (fill_mapindex(d) == 0)
		return (0);
	if (ft_result_colors(d, color) == 0)
		return (0);
	if (fill_grid(d, map) == 0)
		return (0);
	return (1);
}


int		main(int argc, char **argv)
{
	t_flags	d;
	t_color	color;
	t_map	map;

	if (argc != 2)
		return (0);
	// if (argv_check(argv[1], &d) == 0)
	// 	return(write(1, d.error, ft_strlen(d.error) + 1));
	if (check_map(argv, &d, &color, &map) == 0)
		return (write(1, d.error, ft_strlen(d.error) + 1));
	window(&d, &color, &map);
	return (0);
}
