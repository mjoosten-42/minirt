/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/07 13:11:02 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "collision.h"
#include "ray3.h"
#include "shape_masks.h"
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

static t_shape	build_cap(const t_shape *cylinder);
t_collision		collision_caps(const t_shape *cylinder, const t_ray3 *ray);
double			collision_cylinder_inf(const t_shape *cylinder, const t_ray3 *ray);

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;

	coll = collision_none();
	coll.distance = collision_cylinder_inf(cylinder, ray);
	if (coll.distance >= 0)
	{
		coll.shape = cylinder;
		coll.normal = vec3(0, 0, -1);
		coll.point = ray_point(ray, coll.distance);
	}
	else
	{
		coll = collision_caps(cylinder, ray);
		if (coll.shape == NULL)
			return (collision_none());
		coll.shape = cylinder;
	}
	return (coll);
}

double	collision_cylinder_inf(const t_shape *cylinder, const t_ray3 *ray)
{	
	t_ray3		rot_ray;
	t_abc		abc;
	t_v3		point;
	double		t[2];

	rot_ray.origin = vec3_sub(ray->origin, cylinder->origin);
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
	point = ray_point(&rot_ray, t[0]);
	if (point.y < 0 || point.y > cylinder->cy.height)
		return (-1);
	return (t[0]);
}

t_collision	collision_caps(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;
	t_shape		circle;

	circle = build_cap(cylinder);
	coll = collision_circle(&circle, ray);
	if (coll.shape != NULL)
		return (coll);
	circle.origin = vec3_add(cylinder->origin, vec3_mul(cylinder->cy.normal, cylinder->cy.height));
	coll = collision_circle(&circle, ray);
	if (coll.shape != NULL)
		return (coll);
	return (collision_none());
}

static t_shape	build_cap(const t_shape *cylinder)
{
	t_shape	circle;

	circle.origin = cylinder->origin;
	circle.ci.normal = cylinder->cy.normal;
	circle.color = cylinder->color;
	circle.type = SHAPE_CIRCLE;
	circle.material = cylinder->material;
	circle.ci.radius = cylinder->cy.radius;
	return (circle);
}
