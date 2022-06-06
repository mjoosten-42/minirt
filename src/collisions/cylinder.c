/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 15:59:17 by mjoosten         ###   ########.fr       */
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

double	collision_cylinder_inf(const t_shape *cylinder, const t_ray3 *ray);

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;

	coll = collision_none();
	coll.distance = collision_cylinder_inf(cylinder, ray);
	if (coll.distance < 0)
		return (collision_none());
	coll.shape = cylinder;
	coll.normal = ray->direction;
	coll.point = vec3_add(ray->origin, vec3_mul(ray->direction, coll.distance));
	return (coll);
}

double	collision_cylinder_inf(const t_shape *cylinder, const t_ray3 *ray)
{	
	t_ray3		rot_ray;
	t_abc		abc;
	double		t[2];

	rot_ray.origin = vec3_sub(ray->origin, cylinder->origin);
	rot_ray.origin = rodrigues(ray->origin, cylinder->cy.axis, cylinder->cy.angle);
	rot_ray.direction = rodrigues(ray->direction, cylinder->cy.axis, cylinder->cy.angle);
	abc.a = rot_ray.direction.x * rot_ray.direction.x
		+ rot_ray.direction.z * rot_ray.direction.z;
	abc.b = 2 * (rot_ray.direction.x * rot_ray.origin.x
		+ rot_ray.direction.z * rot_ray.origin.z);
	abc.c = rot_ray.origin.x * rot_ray.origin.x
		+ rot_ray.origin.z * rot_ray.origin.z
		- cylinder->cy.radius * cylinder->cy.radius;
	if (_quadratic(t, abc) < 0)
		return (-1);
	return (t[0]);

}