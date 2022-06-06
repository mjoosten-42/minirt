/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_masks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:15:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/06 11:29:32 by mjoosten         ###   ########.fr       */
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
	SHAPE_TRIANGLE,
	SHAPE_SPHERE,
	SHAPE_CYLINDER
}	t_shape_type;

/**
**	SHAPE_PLANE
**	@param normal <t_v3> Normal vector
*/
typedef struct s_mask_plane
{
	t_v3	normal;
}			t_mask_plane;

/**
**	SHAPE_SQUARE
**	@param normal <t_v3> Normal vector
**	@param width <double> Total width
*/
typedef struct s_mask_square
{
	t_v3	normal;
	double	width;
}			t_mask_square;

/**
**	SHAPE_CIRCLE
**	@param normal <t_v3> Normal vector
**	@param radius <double> Radius
*/
typedef struct s_mask_circle
{
	t_v3	normal;
	double	radius;
}			t_mask_circle;

/**
**	SHAPE_TRIANGLE
**	@param point2 <t_v3> Second point
**	@param point3 <t_v3> Third point
*/
typedef struct s_mask_triangle
{
	t_v3	point2;
	t_v3	point3;
}			t_mask_triangle;

/**
**	SHAPE_SPHERE
**	@param radius <double> Radius
*/
typedef struct s_mask_sphere
{
	double	radius;
}			t_mask_sphere;

/**
**	SHAPE_CYLINDER
**	@param normal <t_v3> Normal vector
**	@param diameter <double> Radius
**	@param height <double> Height
**	@param axis <double> Vector to rotate around
**	@param angle <double> Angle of rotation
*/
typedef struct s_mask_cylinder
{
	t_v3	normal;
	double	radius;
	double	height;
	t_v3	axis;
	double	angle;
}			t_mask_cylinder;

#endif
