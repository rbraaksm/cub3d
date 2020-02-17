/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:54:30 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/02/17 12:32:09 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define BUFFER_SIZE 128
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

typedef struct		s_color
{
	unsigned long	floor;
	int				fred;
	int				fgreen;
	int				fblue;
	unsigned long	ceiling;
	int				cred;
	int				cgreen;
	int				cblue;
}					t_color;

typedef struct		s_struct
{
	char			**r;
	int				resx;
	int				resy;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	char			**f;
	char			**c;
	char			*str;
}					t_flags;

typedef struct		s_map
{
	char			**map;
	int				row;
	int				column;
	int				posx;
	int				posy;
}					t_map;

typedef struct		s_vars
{
    void			*mlx;
    void			*win;
	void			*mapimg;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	unsigned int	player;
	double			play_x;
	double			play_y;
	double			tile_h;
	double			tile_w;
	double			rayx;
	double			rayy;
	double			angle;
	double			sidex;
	double			deltax;
	double			sidey;
	double			deltay;
	double			walldist;
	t_map			*map;
	t_flags			*data;
	t_color			*color;
}					t_vars;

int					make_string(char **argv, t_flags *data);
int					fill_mapindex(t_flags *data);
int					ft_result_colors(t_flags *data, t_color *color);
int					fill_grid(t_flags *data, t_map *map);
int					check_grid(t_map *map);

/* check index */
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *str);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);

/* window */

void				window(t_flags *data, t_color *color, t_map *map);
void				ft_make_2d(t_vars *vars);
void				player(t_vars *vars, double move, char d,
					unsigned int color);
void				my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void				ft_findwall(t_vars *vars);
void				ft_view(t_vars *vars, double rot,
					unsigned int color, char c);

void				print(t_map *map);

int					mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color);
#endif
