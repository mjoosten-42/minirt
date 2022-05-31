/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:51:48 by ngerrets          #+#    #+#             */
/*   Updated: 2022/05/31 14:50:10 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ray3.h"
#include "collision.h"
#include <math.h>

# define EPSILON 0.1

t_mask_plane	shape_plane_mask(t_v3 normal)
{
	return ((t_mask_plane){normal});
}

/*     (P0 - l0) . n
** D = -------------
**		   l . n
*/

t_collision	shape_plane_collision(const t_shape *plane, const t_ray3 *ray)
{
	t_mask_plane	*mask;
	t_collision		coll;
	double			t;

	mask = (t_mask_plane *)plane->mask;
	if (vec3_dot(ray->direction, mask->normal) == 0)
		return (collision_none());
	t = vec3_dot(vec3_sub(plane->origin, ray->origin), mask->normal) / vec3_dot(ray->direction, mask->normal);
	coll.point = vec3_add(ray->origin, vec3_mul(ray->direction, t));
	coll.shape = (t_shape *)plane;
	coll.normal = ray->direction;
	return (coll);
}
