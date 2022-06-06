/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 14:57:32 by mjoosten         ###   ########.fr       */
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

t_collision	collision_cylinder_inf(const t_shape *cylinder, const t_ray3 *ray);

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;

	coll = collision_cylinder_inf(cylinder, ray);
	return (coll);
}

t_collision	collision_cylinder_inf(const t_shape *cylinder, const t_ray3 *ray)
{	
	t_collision	coll;
	t_v3		rot;
	t_v3		mov;
	t_abc		abc;
	double		t[2];

	mov = vec3_sub(ray->origin, cylinder->origin);
	rot = rodrigues(ray->direction, cylinder->cy.axis, cylinder->cy.angle);
	abc.a = rot.x * rot.x + rot.z * rot.z;
	abc.b = 2 * (rot.x * mov.x + rot.z * mov.z);
	abc.c = mov.x * mov.x + mov.z * mov.z
		- cylinder->cy.radius * cylinder->cy.radius;
	if (_quadratic(t, abc) < 0)
		return (collision_none());
	coll.shape = (t_shape *)cylinder;
	coll.distance = t[0];
	coll.point = vec3_add(cylinder->origin, vec3_add(ray->origin, vec3_mul(ray->direction, t[0])));
	if (coll.point.z > cylinder->cy.height)
		return (collision_none());
	coll.normal = ray->direction;
	return (coll);

}