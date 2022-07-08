/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_masks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:15:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/08 11:18:44 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_MASKS_H
# define SHAPE_MASKS_H

# include "vec3.h"

/**
**	SHAPE_SPHERE
**	@param radius <double> Radius
*/
typedef struct s_mask_sphere
{
	double	radius;
}			t_mask_sphere;

/**
**	SHAPE_PLANE
**	@param n <t_v3> Normal vector
*/
typedef struct s_mask_plane
{
	t_v3	n;
}			t_mask_plane;

/**
**	SHAPE_CYLINDER
**	@param n <t_v3> Normal vector
**	@param radius <double> Radius
**	@param height <double> Height
**	@param axis <double> Vector to rotate around
**	@param angle <double> Angle of rotation
*/
typedef struct s_mask_cylinder
{
	t_v3	n;
	double	radius;
	double	height;
	t_v3	axis;
	double	angle;
}			t_mask_cylinder;

/**
**	SHAPE_CONE
**	@param n <t_v3> Normal vector
**	@param radius <t_v3> Radius at cone base
**	@param height <t_v3> Height
**	@param angle <t_v3> Holds cos(angle)^2
*/
typedef struct s_mask_cone
{
	t_v3	n;
	double	radius;
	double	height;
	double	angle;
}			t_mask_cone;

#endif
