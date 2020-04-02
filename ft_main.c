/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/04/02 15:19:43 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

int		check_input(int argc, char **argv, t_flags *d)
{
	int		i;

	if (argc < 2)
	{
		ERROR = "ERROR: NEED ONE MORE AGRUMENT\n";
		return (0);
	}
	ERROR = "ERROR: IT'S NOT A .CUB FILE\n";
	i = ft_strlen(argv[1]);
	if (argv[1][i - 1] != 'b')
		return (0);
	if (argv[1][i - 2] != 'u')
		return (0);
	if (argv[1][i - 3] != 'c')
		return (0);
	if (argv[1][i - 4] != '.')
		return (0);
	ERROR = NULL;
	return (1);
}

int		check_map(char **argv, t_flags *d, t_color *color)
{
	if (make_string(argv, d) == 0)
		return (0);
	if (fill_mapindex(d) == 0)
		return (0);
	if (ft_result_colors(d, color) == 0)
		return (0);
	if (fill_grid(d) == 0)
		return (0);
	if (check_grid(d) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_flags	d;
	t_color	color;

	if (check_input(argc, argv, &d) == 0)
		return (write(1, d.error, ft_strlen(d.error)));
	if (check_map(argv, &d, &color) == 0)
		return (write(1, d.error, ft_strlen(d.error)));
	window(&d, &color);
	return (0);
}
