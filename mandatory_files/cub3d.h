/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:54:30 by rbraaksm      #+#    #+#                 */
/*   Updated: 2020/04/22 14:23:50 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 30
# define CHECK 42424242
# define XPM mlx_xpm_file_to_image
# define ADDR mlx_get_data_addr
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

typedef struct		s_player
{
	float			y;
	float			x;
	float			crab;
	float			walk;
	float			look;
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
	float			adjust;
	float			dist;
}					t_ray;

typedef struct		s_sprite
{
	float			x;
	float			y;
	float			x_hit;
	float			y_hit;
	float			perc;
	float			dist;
	float			angle;
	int				ray;
	float			ydir;
	float			xdir;
	float			x_incr;
	float			y_incr;
	float			all;
	float			start;
}					t_sprite;

typedef struct		s_vars
{
	int				fd;
	int				i;
	float			start;
	int				save;
	int				check;
	char			**map;
	int				column;
	int				row_count;
	int				row_i;
	int				resx;
	int				resy;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*sp;
	unsigned long	floor;
	int				fred;
	int				fgreen;
	int				fblue;
	unsigned long	ceiling;
	int				cred;
	int				cgreen;
	int				cblue;
	char			*str;
	char			*error;
	void			*mlx;
	void			*win;
	void			*no_mlx;
	void			*ea_mlx;
	void			*so_mlx;
	void			*we_mlx;
	void			*sp_mlx;
	void			*no_img;
	void			*ea_img;
	void			*so_img;
	void			*we_img;
	void			*sp_img;
	char			*add[7];
	int				bits[6];
	int				ll[6];
	int				en[6];
	int				img_height[5];
	int				img_width[5];
	void			*img1;
	void			*img2;
	int				img;
	int				tex;
	int				x;
	int				si;
	int				screen_x;
	int				screen_y;
	int				stepx;
	int				stepy;
	float			height;
	float			c;
	float			f;
	int				middle;
	float			end;
	float			xperc;
	float			yperc;
	t_sprite		s[200];
	t_ray			ray;
	t_player		player;
}					t_vars;

int					check_input(int argc, char **argv, t_vars *v);
int					make_string(char **argv, t_vars *v);
int					fill_parser(t_vars *v);
char				*path(t_vars *v, char *s1, char c);
void				resolution(t_vars *v, char *str);
void				data_floor(t_vars *v, char *str);
void				data_ceiling(t_vars *v, char *str);
int					fill_grid(t_vars *v);
int					check_map(t_vars *v);
int					ft_strchr(t_vars *v, char c, int row, int column);
int					error_check(t_vars *v, char *str);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					free_function(t_vars *v);
int					action(t_vars *v);
int					keyrelease(int keycode, t_vars *v);
int					keypress(int keycode, t_vars *v);
void				start_game(t_vars *v);
int					exit_game(t_vars *v);
void				screenshot(t_vars *v);
void				rotate_player(t_vars *v, float rot);
void				move_player(t_vars *v, float move);
void				crab_player(t_vars *v, float move);
void				rays(t_vars *vars);
void				draw_wall(t_vars *v);
void				find_side_delta(t_vars *v);
int					sprite(t_vars *v, int side, int mapy, int mapx);
void				my_mlx_pixel_put(t_vars *v, int x, int y, int color);
void				my_image_put(t_vars *v, int x, int y);
void				my_mlx_pixel_put_sprite(t_vars *v, int x, int y);
#endif
