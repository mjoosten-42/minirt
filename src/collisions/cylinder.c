/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/16 11:03:14 by mjoosten         ###   ########.fr       */
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

	coll.shape = cylinder;
	coll.distance = collision_cy_inf(cylinder, ray);
	if (coll.distance >= 0)
	{
		coll.point = ray_point(ray, coll.distance);
		tmp = vec3_sub(coll.point, cylinder->o);
		coll.normal = vec3_norm(vec3_sub(tmp,
			vec3_project(tmp, cylinder->n)));
		coll.point = ray_point(ray, coll.distance);
		return (coll);
	}
	coll = collision_caps(cylinder, ray);
	if (coll.shape != NULL)
	{
		coll.shape = cylinder;
		return (coll);
	}
	return (collision_none());
}

double	collision_cy_inf(const t_shape *cylinder, const t_ray3 *ray)
{	
	t_ray3		rot;
	t_abc		abc;
	double		t[2];
	double		y;

	rot.o = vec3_sub(ray->o, cylinder->o);
	rot.o = rodrigues(rot.o, cylinder->cy.axis, cylinder->cy.angle);
	rot.d = rodrigues(ray->d, cylinder->cy.axis, cylinder->cy.angle);
	abc.a = rot.d.x * rot.d.x + rot.d.z * rot.d.z;
	abc.b = 2 * (rot.d.x * rot.o.x + rot.d.z * rot.o.z);
	abc.c = rot.o.x * rot.o.x + rot.o.z * rot.o.z
		- cylinder->cy.radius * cylinder->cy.radius;
	if (quadratic(t, abc) < 0)
		return (-1);
	y = rot.o.y + t[0] * rot.d.y;
	if (y < 0 || y > cylinder->cy.height)
		return (-1);
	return (t[0]);
}

t_collision	collision_caps(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;
	t_shape		plane;

	plane = *cylinder;
	coll = collision_plane(&plane, ray);
	if (coll.shape != NULL)
		if (vec3_distance(coll.point, plane.o) < cylinder->cy.radius)
			return (coll);
	plane.o = vec3_add(cylinder->o,
			vec3_mul(cylinder->n, cylinder->cy.height));
	coll = collision_plane(&plane, ray);
	if (coll.shape != NULL)
		if (vec3_distance(coll.point, plane.o) < cylinder->cy.radius)
			return (coll);
	return (collision_none());
}
