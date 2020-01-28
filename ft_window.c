/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_window.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/22 15:52:39 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/28 12:11:32 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx/mlx.h"
#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		ft_close(int keycode, t_vars *vars)
{
	if (keycode == 53)
    	mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}

int		mouse(int x, int y, t_vars *vars)
{
	if ((x > 0 && x < 800) && (y > 0 && y < 800))
	{
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0x000000FF, "Hello");
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0xFF000000, "Bye");
		printf("x = %d\n", x);
		printf("y = %d\n", y);
	}
	if ((x < 0 && x > 800) && (y < 0 && y > 800))
	{
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0xFF000000, "Hello");
		mlx_string_put(vars->mlx, vars->win, 400, 400, 0x000000FF, "bye");
	}
		return (1);
}

void	window(t_flags *data, t_color *color, t_map *map)
{
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, data->resx, data->resy, "CUB3D");
	
		/*close window */
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);

	/* mouse */
	// mlx_hook(vars.win, 6, 1L<<6, mouse, &vars);

	int		x;
	double	posx = map->posx; // x start position
	double	posy = map->posy; // y start position
	double	dirx = -1; // initial direction vector
	double	diry = 0; // initial direction vector
	double	planex = 0; //the 2d raycaster version of camera plane
	double	planey = 0.66; //the 2d raycaster version of camera plane
	
	while (1)
	{
		img.img = mlx_new_image(vars.mlx, data->resx, data->resy);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
		x = 0;
		while (x < data->resx)
		{
			// calculate ray position and direction
			double	camerax = 2 * x / (double)data->resx - 1; // x-coordinate in camera space
			double	raydirx= dirx + planex * camerax;
			double	raydiry = diry + planey * camerax;

			// Which bos of te map we're in
			int		mapx = map->posx;
			int		mapy = map->posy;

			// Length of ray from current position to next x or y-side
     		double	sidedistx = 0;
			double	sidedisty = 0;

			//length of ray from one x or y-side to next x or y-side
			double deltadistx = std::abs(1 / raydirx);
			double deltadisty = std::abs(1 / raydiry);
			double perpwalldist;

			//what direction to step in x or y-direction (either +1 or -1)
			int stepx;
			int stepy;

			int hit = 0; //was there a wall hit?
			int side; //was a NS or a EW wall hit?

			//calculate step and initial sideDist
			if (raydirx < 0)
			{
				stepx = -1;
				sidedistx = (posx - mapx) * deltadistx;
			}
			else
			{
				stepx = 1;
				sidedistx = (mapx + 1.0 - posx) * deltadistx;
			}
			if (raydiry < 0)
			{
				stepy = -1;
				sidedisty = (posy - mapy) * deltadisty;
			}
			else
			{
				stepy = 1;
				sidedisty = (mapy + 1.0 - posy) * deltadisty;
			}
			//perform DDA
			while (hit == 0)
			{
				//jump to next map square, OR in x-direction, OR in y-direction
				if (sidedistx < sidedisty)
				{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
				}
				else
				{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
				}
				//Check if ray has hit a wall
				if (map->map[mapx][mapy] > 0) hit = 1;
			}
			//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
			if (side == 0) perpwalldist = (mapx - posx + (1 - stepx) / 2) / raydirx;
			else           perpwalldist = (mapy - posy + (1 - stepy) / 2) / raydiry;

			 //Calculate height of line to draw on screen
			int lineheight = (int)(data->resy / perpwalldist);

			//calculate lowest and highest pixel to fill in current stripe
			int drawstart = - lineheight / 2 + data->resy / 2;
			if(drawstart < 0) drawstart = 0;
			int drawend = lineheight / 2 + data->resy / 2;
			if(drawend >= data->resy) drawend = data->resy - 1;

			//choose wall color
			// switch(map->map[mapx][mapy])
			// {
			// 	case 1:  0x00ff0000;  break; //red
			// 	case 2:  0x0000ff00;  break; //green
			// 	case 3:  0x000000ff;  break; //blue
			// 	case 4:  0x00a0a0a0;  break; //white
			// 	default: 0x000b0b0b; break; //yellow
			// }

			// //give x and y sides different brightness
			// if (side == 1) {color = color / 2;}

			// //draw the pixels of the stripe as a vertical line
			// verline(x, drawstart, drawend, color);
      }
	}
	color->floor = 0;
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}