/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/02 07:33:38 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		check_map(char **argv, t_flags *d, t_color *color, t_map *map)
{
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
	if (check_map(argv, &d, &color, &map) == 0)
		return (write(1, d.error, ft_strlen(d.error) + 1));
	window(&d, &color, &map);
	return (0);
}
