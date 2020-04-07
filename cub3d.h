/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:54:30 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/07 15:06:27 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 128
# include "definitions.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <mlx.h>

typedef struct		s_struct
{
	int				save;
	int				check;
	char			**map;
	int				column;
	int				row_count;
	int				row_i;
	char			position;
	float			play_x;
	float			play_y;
	char			**r;
	int				resx;
	int				resy;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned long	floor;
	int				fred;
	int				fgreen;
	int				fblue;
	unsigned long	ceiling;
	int				cred;
	int				cgreen;
	int				cblue;
	char			**f;
	char			**c;
	char			*str;
	char			*error;
}					t_flags;

// typedef struct		s_game
// {
// 	void			*mlx;
// 	void			*win;
// 	void			*img1;
// 	void			*img2;
// 	char			*addr;
// 	int				bits_per_pixel;
// 	int				line_length;
// 	int				endian;
// 	int				active_img;
// 	void			*new_img;
// }					t_game;

typedef struct		s_tex
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
	float			x_tex;
	float			y_tex;
}					t_tex;

typedef struct		s_textures
{
	t_tex			*n_tex;
	t_tex			*e_tex;
	t_tex			*s_tex;
	t_tex			*w_tex;
	t_tex			*sprite;
}					t_texture;

typedef struct		s_player
{
	float			y;
	float			x;
	int				move_f;
	int				move_b;
	int				move_l;
	int				move_r;
	int				rotate_l;
	int				rotate_r;
}					t_player;

typedef struct		s_ray
{
	float			playdir;
	float			angle;
	float			rayx;
	float			rayy;
	float			sidex;
	float			deltax;
	float			sidey;
	float			deltay;
	float			raydist;
	float			finaldist;
	float			opp;
	float			adjust;
	float			walldist;
	int				side_hit;
	int				sprite;
	int				sprite_hit;
}					t_ray;

typedef struct		s_sprite
{
	float			middle_x;
	float			middle_y;
	float			x_hit;
	float			y_hit;
	float			angle;
	float			active_angle;
	float			x_angle;
	float			y_angle;
	float			x_hit_angle;
	float			y_hit_angle;
	float			x_incr;
	float			y_incr;
	float			x_angle_incr;
	float			y_angle_incr;
	float			schuin;
	float			start;
	float			finaldist[200];
	float			perc[200];
}					t_sprite;

typedef struct		s_vars
{
	void			*mlx;
	void			*win;
	void			*img1;
	void			*img2;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				active_img;
	void			*new_img;
	float			tile_h;
	float			tile_w;
	int				stepx;
	int				stepy;
	int				i;
	int				index;
	int				screen_x;
	int				screen_y;
	t_sprite		*s;
	t_ray			*ray;
	t_player		*player;
	t_texture		*textures;
	t_flags			*d;
	// t_game			*g;
}					t_vars;

int					check_input(int argc, char **argv, t_flags *d);
int					make_string(char **argv, t_flags *data);
int					fill_parser(t_flags *data);
void    			north(t_flags *d, const char *s1, char c);
void    			east(t_flags *d, const char *s1, char c);
void    			south(t_flags *d, const char *s1, char c);
void    			west(t_flags *d, const char *s1, char c);
void    			sprite(t_flags *d, const char *s1, char c);
void				resolution(t_flags *d, char *str);
void				data_floor(t_flags *d, char *str);
void				data_ceiling(t_flags *d, char *str);
int					fill_grid(t_flags *data);
int					check_grid(t_flags *data);
int					ft_strchr(t_flags *d, char c, int row, int column);

/* check index */
// char				*ft_strdup(const char *s1);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);

/* window */

void				window(t_flags *data);
void				struct_info(t_vars *v);
void				ft_make_2d(t_vars *vars);
void				bmp(t_vars *v);
void				player(t_vars *vars, float move);
void				my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void				ft_findwall(t_vars *vars);
void				ft_view(t_vars *vars, float rot);
void				draw(t_vars *v);
void				draw_wall(t_vars *v);
void				draw_sprite(t_vars *v);

void				print(t_flags *d);

/* NEW */

void				find_side_delta(t_vars *v);
void				find_hit(t_vars *v);


int					mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color);
void				my_mlx_pixel_put2(t_vars *v, int x, int y, int color);
int					my_mlx_pixel_putwall(t_vars *v, int x, int y, int color);
void				my_image_put(t_vars *v, t_tex *tex, int x, int y);
void				my_sprite_put(t_vars *v, int x, int y);
t_tex				*texture_info(t_vars *v, char *path);
#endif