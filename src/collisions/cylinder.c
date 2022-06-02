/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/02 17:11:48 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "shape.h"
#include "shape_masks.h"
#include <math.h>
#include "equations.h"

/*	https://www.pbr-book.org/3ed-2018/Shapes/Cylinders
**	r^2 = x^2 + z^2
**	x = o.x + t * d.x
**	z = o.z + t * d.z
**	r^2 = (o.x + t * d.x)^2 + (o.z + t * d.z)^2
**	a = d.x^2 + d.x^2
**	b = 2(d.x * o.x + d.z * o.z)
**	c = o.x^2 + o.z^2 - r^2
*/

t_v3	rodrigues(t_v3 v, t_v3 axis, double angle);

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision		coll;
	t_mask_cylinder	*mask;
	t_v3			rot;
	t_v3			axis;
	double			angle;
	t_abc			abc;
	double			radius;
	double			t[2];
	double			d;

	coll = collision_none();
	mask = (t_mask_cylinder *)cylinder->mask;
	angle = vec3_angle(mask->normal, vec3(0, 1, 0));
	axis = vec3_cross(mask->normal, vec3(0, 1, 0));
	vec3_normalize(&axis);
	rot = rodrigues(ray->direction, axis, angle);
	radius = mask->diameter / 2;
	abc.a = ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z;
	abc.b = 2 * (ray->direction.x * ray->origin.x + ray->direction.z * ray->origin.z);
	abc.c = ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - (radius * radius);
	d = _discriminant(abc);
	if (d < 0)
		return (coll);
	_quadratic(t, abc, d);
	coll.shape = cylinder;
	coll.distance = t[0];
	coll.point = vec3_add(ray->origin, vec3_mul(ray->direction, t[0]));
	coll.normal = ray->direction;
	return (coll);
}

t_v3	rodrigues(t_v3 v, t_v3 axis, double angle)
{
	t_v3	t1;
	t_v3	t2;
	t_v3	t3;

	t1 = vec3_mul(v, cos(angle));
	t2 = vec3_mul(vec3_cross(axis, v), sin(angle));
	t3 = vec3_mul(vec3_mul(axis, vec3_dot(axis, v)), 1 - cos(angle));
	return (vec3_add(vec3_add(t1, t2), t3));
}
