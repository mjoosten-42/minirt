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

typedef enum e_shape_type
{
	SHAPE_NONE = 0,
	SHAPE_PLANE,
	SHAPE_SQUARE,
	SHAPE_CIRCLE,
	SHAPE_TRIANGLE
}	t_shape_type;

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

/* SHAPE_TRIANGLE */
typedef struct s_mask_triangle
{
	t_v3	point2;
	t_v3	point3;
}			t_mask_triangle;

#endif
