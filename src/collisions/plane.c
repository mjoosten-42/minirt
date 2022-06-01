/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:00:30 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/01 12:00:17 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "collision.h"
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
	t_mask_plane	*mask;
	t_collision		coll;
	double			denom;
	double			t;

	coll = collision_none();
	mask = (t_mask_plane *)plane->mask;
	denom = vec3_dot(ray->direction, mask->normal);
	if (fabs(denom) < __DBL_EPSILON__)	
		return (coll);
	t = vec3_dot(vec3_sub(plane->origin, ray->origin), mask->normal) / denom;
	if (t > __DBL_EPSILON__)
	{
		coll.point = vec3_add(ray->origin, vec3_mul(ray->direction, t));
		coll.shape = (t_shape *)plane;
		coll.normal = mask->normal;
		coll.distance = t;
	}
	return (coll);
}
