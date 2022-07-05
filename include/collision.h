/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 11:29:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 15:08:43 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "vec3.h"
# include "ray3.h"
# include "program.h"
# include "shape.h"

/**
**	Collision data of ray intersecting a shape
**	@param point <t_v3> Point-Vector of world collision
**	@param normal <t_v3> Normal vector of collision
**	@param shape <t_shape*> Shape that got collided with
**	@param distance <double> Distance to the collision point, in t
**	@param inside <bool> Whether collision is inside an object
*/
typedef struct s_collision
{
	t_v3			point;
	t_v3			normal;
	t_shape			*shape;
	double			distance;
	bool			inside;
}					t_collision;

/* raycast.c */
t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray);

/* collision.c */
t_collision	collision_none(void);

t_collision	collision_sphere(t_shape *sphere, const t_ray3 *ray);
t_collision	collision_plane(t_shape *plane, const t_ray3 *ray);
t_collision	collision_cylinder(t_shape *cylinder, const t_ray3 *ray);
t_collision	collision_cone(t_shape *cone, const t_ray3 *ray);

#endif
