/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 11:28:24 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/16 10:56:00 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	header_bmp(t_vars *v, int fd)
{
	unsigned int	size;
	unsigned int	first_pix;

	first_pix = 54;
	size = v->d->resy * v->d->resx * 4 + 54;
	write(fd, "BM", 2);
	write(fd, &size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
}

static void	header_dip_bmp(t_vars *v, int fd)
{
	unsigned int	headersize;
	unsigned short	plain;
	unsigned short	bits_per_pixel;

	headersize = 40;
	plain = 1;
	bits_per_pixel = 32;
	write(fd, &headersize, 4);
	write(fd, &v->d->resx, 4);
	write(fd, &v->d->resy, 4);
	write(fd, &plain, 2);
	write(fd, &bits_per_pixel, 2);
	while (plain <= 24)
	{
		write(fd, "\0", 1);
		plain++;
	}
}

static void	write_pixels(t_vars *v, int fd)
{
	int x;
	int line_length;

	line_length = 0;
	if (v->d->resx % 64 != 0)
		line_length = 1;
	line_length = (line_length + (v->d->resx / 64)) * 256;
	x = 0;
	v->d->resy -= 1;
	while (v->d->resy >= 0)
	{
		while (x < v->d->resx)
		{
			write(fd, &v->addr[v->d->resy * line_length + x * 4], 4);
			x++;
		}
		x = 0;
		v->d->resy--;
	}
}

void		screenshot(t_vars *v)
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
