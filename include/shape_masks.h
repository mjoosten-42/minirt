/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_masks.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:15:29 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/16 13:20:13 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_MASKS_H
# define SHAPE_MASKS_H

# include "vec3.h"

/* SHAPE_PLANE */
typedef struct s_mask_plane
{
	t_v3	normal;
}			t_mask_plane;

/* SHAPE_SQUARE */
typedef struct s_mask_square
{
	t_v3	normal;
	double	width;
}			t_mask_square;

/* SHAPE_CIRCLE */
typedef struct s_mask_cicle
{
	t_v3	normal;
	double	radius;
}			t_mask_circle;

#endif
