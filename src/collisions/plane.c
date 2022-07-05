/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:30 by mjoosten          #+#    #+#             */
/*   Updated: 2022/07/05 14:44:12 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "vec3.h"
#include "shape.h"
#include "shape_masks.h"
#include <math.h>

/* https://en.wikipedia.org/wiki/Line–plane_intersection
**
**     (p0 - l0) . n
** t = -------------
**		   l . n
**
** p0: plane origin
** l0: ray origin
** n: plane normal
** l: ray direction
**
** if the denominator l . n is zero, the ray is perpendicular to the plane
*/
t_collision	collision_plane(const t_shape *plane, const t_ray3 *ray)
{
	t_collision	coll;
	double		d;
	double		t;

	d = vec3_dot(ray->d, plane->pl.n);
	if (fabs(d) < __DBL_EPSILON__)
		return (collision_none());
	t = vec3_dot(vec3_sub(plane->o, ray->o), plane->pl.n) / d;
	if (t < __DBL_EPSILON__)
		return (collision_none());
	coll.shape = plane;
	coll.distance = t;
	coll.point = ray_point(ray, t);
	coll.normal = plane->pl.n;
	if (d >= 0)
		coll.normal = vec3_mul(coll.normal, -1.0);
	coll.inside = false;
	return (coll);
}
