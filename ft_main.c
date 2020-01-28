/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/28 09:19:56 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		check_map(char **argv, t_flags *data, t_color *color, t_map *map)
{
	if (make_string(argv, data) == 0)
		return (0);
	if (fill_mapindex(data) == 0)
		return (0);
	if (ft_result_colors(data, color) == 0)
		return (0);
	if (fill_grid(data, map) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_flags	data;
	t_color	color;
	t_map	map;

	if (argc != 2)
		return (0);
	if (check_map(argv, &data, &color, &map) == 0)
		return (write(1, "INVALID MAP\n", 11));
	window(&data, &color, &map);
	return (0);
}
