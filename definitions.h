/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   definitions.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbraaksm <rbraaksm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 13:23:06 by rbraaksm       #+#    #+#                */
/*   Updated: 2020/04/02 15:11:31 by rbraaksm      ########   odam.nl         */
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
# define MAP d->map
# define POS d->position
# define PLAY_X d->play_x
# define PLAY_Y d->play_y
# define ROW_I d->row_i
# define ROW_C d->row_count
# define COLUMN d->column

/* RAY STRUCT */
# define PLAYDIR v->ray->playdir
# define RAY_ANGLE v->ray->angle
# define RAYX v->ray->rayx
# define RAYY v->ray->rayy
# define SIDEX v->ray->sidex
# define SIDEY v->ray->sidey
# define DELTAX v->ray->deltax
# define DELTAY v->ray->deltay
# define WALLDIST v->ray->walldist
# define RAY_FINAL v->ray->finaldist
# define SPRITE_HIT v->ray->sprite_hit
# define HAS_SPRITE v->ray->sprite
# define SIDE_HIT v->ray->side_hit

/* PLAYER STRUCT */
# define PLAYER_X v->player->x
# define PLAYER_Y v->player->y
# define MOVE_LEFT v->player->move_l
# define MOVE_RIGHT v->player->move_r
# define MOVE_FORWARD v->player->move_f
# define MOVE_BACKWARDS v->player->move_b

/* SPRITE STRUCT */
# define MIDDLE_X v->s->middle_x
# define MIDDLE_Y v->s->middle_y
# define SPRITE_ANGLE v->s->angle
# define SCHUIN v->s->schuin
# define X_HIT v->s->x_hit
# define Y_HIT v->s->y_hit
# define X_ANGLE v->s->x_angle
# define Y_ANGLE v->s->y_angle
# define Y_INCR v->s->y_incr
# define X_INCR v->s->x_incr
# define X_HIT_ANGLE v->s->x_hit_angle
# define Y_HIT_ANGLE v->s->y_hit_angle
# define X_ANGLE_INCR v->s->x_angle_incr
# define Y_ANGLE_INCR v->s->y_angle_incr
# define SPRITE_FINAL v->s->finaldist
# define PERC v->s->perc
# define START v->s->start

/* VARS STRUCT */
# define STEP_X v->stepx
# define STEP_Y v->stepy
# define TILE_W v->tile_w
# define TILE_H v->tile_h
# define SPRITE_I v->index

#endif