/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 10:44:36 by mjoosten         ###   ########.fr       */
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

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision		coll;
	t_mask_cylinder	*mask;
	t_v3			rot;
	t_abc			abc;
	double			radius;
	double			t[2];
	double			d;

	coll = collision_none();
	mask = (t_mask_cylinder *)cylinder->mask;
	rot = rodrigues(ray->direction, mask->axis, mask->angle);
	radius = mask->diameter / 2;
	abc.a = rot.x * rot.x + rot.z * rot.z;
	abc.b = 2 * (rot.x * ray->origin.x + rot.z * ray->origin.z);
	abc.c = ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - (radius * radius);
	d = _discriminant(abc);
	if (d < 0)
		return (coll);
	_quadratic(t, abc, d);
	coll.shape = (t_shape *)cylinder;
	coll.distance = t[0];
	coll.point = vec3_add(ray->origin, vec3_mul(ray->direction, t[0]));
	coll.normal = ray->direction;
	return (coll);
}
