/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_main.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:50:42 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/14 14:01:25 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(char **argv, t_flags *d)
{
	if (make_string(argv, d) == 0)
		return (0);
	if (fill_parser(d) == 0)
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

	if (check_input(argc, argv, &d) == 0)
		return (write(1, d.error, ft_strlen(d.error)));
	if (check_map(argv, &d) == 0)
		return (write(1, d.error, ft_strlen(d.error)));
	window(&d);
	printf("test\n");
	return (0);
}
