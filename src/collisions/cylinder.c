/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/13 13:13:36 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "ray3.h"
#include "shape.h"
#include "shape_masks.h"
#include "equations.h"

// https://www.pbr-book.org/3ed-2018/Shapes/Cylinders

t_collision		collision_caps(const t_shape *cylinder, const t_ray3 *ray);
double			collision_cy_inf(const t_shape *cylinder, const t_ray3 *ray);

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;
	t_v3		tmp;

	coll = collision_none();
	coll.distance = collision_cy_inf(cylinder, ray);
	if (coll.distance >= 0)
	{
		coll.shape = cylinder;
		coll.point = ray_point(ray, coll.distance);
		tmp = vec3_sub(coll.point, cylinder->o);
		coll.normal = vec3_sub(tmp,	vec3_project(tmp, cylinder->cy.normal));
		vec3_normalize(&coll.normal);
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

double	collision_cy_inf(const t_shape *cylinder, const t_ray3 *ray)
{	
	t_ray3		rot_ray;
	t_abc		abc;
	t_v3		point;
	double		t[2];

	rot_ray.o = vec3_sub(ray->o, cylinder->o);
	rot_ray.o = rodrigues(rot_ray.o, cylinder->cy.axis, cylinder->cy.angle);
	rot_ray.d = rodrigues(ray->d, cylinder->cy.axis, cylinder->cy.angle);
	abc.a = rot_ray.d.x * rot_ray.d.x + rot_ray.d.z * rot_ray.d.z;
	abc.b = 2 * (rot_ray.d.x * rot_ray.o.x + rot_ray.d.z * rot_ray.o.z);
	abc.c = rot_ray.o.x * rot_ray.o.x + rot_ray.o.z * rot_ray.o.z
		- cylinder->cy.radius * cylinder->cy.radius;
	if (quadratic(t, abc) < 0)
		return (-1);
	point = ray_point(&rot_ray, t[0]);
	if (point.y < 0 || point.y > cylinder->cy.height)
		return (-1);
	return (t[0]);
}

t_collision	collision_caps(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;
	t_shape		plane;

	plane = *cylinder;
	plane.type = SHAPE_PLANE;
	plane.pl.normal = cylinder->cy.normal;
	coll = collision_plane(&plane, ray);
	if (coll.shape != NULL)
		if (vec3_distance(coll.point, plane.o) < cylinder->cy.radius)
			return (coll);
	plane.o = vec3_add(cylinder->o,
			vec3_mul(cylinder->cy.normal, cylinder->cy.height));
	coll = collision_plane(&plane, ray);
	if (coll.shape != NULL)
		if (vec3_distance(coll.point, plane.o) < cylinder->cy.radius)
			return (coll);
	return (collision_none());
}
