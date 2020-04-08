/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 11:28:24 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/08 16:13:08 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	header_bmp(t_vars *v, int fd)
{
	unsigned int	size;
	unsigned int	first_pix;

	first_pix = 54;
	size = v->RESY * v->RESX * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
}

void	header_dip_bmp(t_vars *v, int fd)
{
	unsigned int	headersize;
	unsigned short	plain;
	unsigned short	bits_per_pixel;

	headersize = 40;
	plain = 1;
	bits_per_pixel = 32;
	write(fd, &headersize, 4);
	write(fd, &v->RESX, 4);
	write(fd, &v->RESY, 4);
	write(fd, &plain, 2);
	write(fd, &bits_per_pixel, 2);
	while (plain <= 24)
	{
		write(fd, "\0", 1);
		plain++;
	}
}

void	write_pixels(t_vars *v, int fd)
{
	int x;
	int line_length;

	line_length = 0;
	if (v->RESX % 64 != 0)
		line_length = 1;
	line_length = (line_length + (v->RESX / 64)) * 256;
	x = 0;
	v->RESY -= 1;
	while (v->RESY >= 0)
	{
		while (x < v->RESX)
		{
			write(fd, &v->addr[v->RESY * line_length + x * 4], 4);
			x++;
		}
		x = 0;
		v->RESY--;
	}
}

void	screenshot(t_vars *v)
{
	int	fd;

	fd = open("screenshot.bmp", O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (fd < 0)
	{
		write(1, "Open failed\n", 12);
		return ;
	}
	header_bmp(v, fd);
	header_dip_bmp(v, fd);
	write_pixels(v, fd);
}
