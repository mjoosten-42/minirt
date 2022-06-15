/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_masks.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:15:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/15 15:39:52 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_MASKS_H
# define SHAPE_MASKS_H

# include "vec3.h"

typedef enum e_shape_type
{
	SHAPE_NONE,
	SHAPE_SPHERE,
	SHAPE_PLANE,
	SHAPE_CYLINDER,
	SHAPE_CONE
}	t_shape_type;

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
	double	radius;
	double	height;
	t_v3	axis;
	double	angle;
}			t_mask_cylinder;

/**
**	SHAPE_CONE
**	@param normal <t_v3> Normal vector
*/
typedef struct s_mask_cone
{
	double	height;
	double	angle;
}			t_mask_cone;

#endif
