/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 13:23:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/03/13 14:22:01 by rbraaksm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef DEFINITIONS_H
# define DEFINTIONS_H

/* COLOR STRUCT */
# define FLOOR color->floor
# define FRED color->fred
# define FGREEN color->fgreen
# define FBLUE color->fblue
# define CEILING color->ceiling
# define CRED color->cred
# define CGREEN color->cgreen
# define CBLUE color->cblue

/* FLAGS STRUCT */
# define ERROR d->error
# define RESX d->resx
# define RESY d->resy
# define RES d->r
# define NORTH d->no
# define SOUTH d->so
# define WEST d->we
# define EAST d->ea
# define SPRITE d->s
# define FSTR d->f
# define CSTR d->c
# define STR d->str

/* MAP STRUCT */
# define MAP map->map
#endif