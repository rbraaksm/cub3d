/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 13:54:30 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/01/22 15:54:22 by rbraaksm      ########   odam.nl         */
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

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

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
	unsigned long	floor;
	int				fred;
	int				fgreen;
	int				fblue;
	char			**c;
	unsigned long	ceiling;
	int				cred;
	int				cgreen;
	int				cblue;
	char			*str;
	char			**map;
}					t_flags;

int					make_string(char **argv, t_flags *data);
int					fill_mapindex(t_flags *data);
int					ft_result_colors(t_flags *data);
int					fill_grid(t_flags *data);
int					check_grid(t_flags *data, int row);

/* check index */
char				*ft_strdup(const char *s1);
int					ft_strlen(const char *str);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);

/* window */

void				window(t_flags *data);
void				print(t_flags *data);

#endif
