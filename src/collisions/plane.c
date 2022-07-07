/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plane.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 11:00:30 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/07 14:22:22 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "vec3.h"
#include "shape.h"
#include "shape_masks.h"
#include <math.h>

// https://en.wikipedia.org/wiki/Line–plane_intersection

t_v3	plane_get_coordinates(const t_collision *coll)
{
	t_v3	v;
	t_v3	right;
	t_v3	up;
	t_v3	r;

	v = vec3_sub(coll->shape->o, coll->point);
	right = vec3_cross((t_v3){0, 1, 0}, coll->shape->pl.n);;
	if (vec3_length(right) < 1.0)
		right = (t_v3){1, 0, 0};
	else
		right = vec3_norm(right);
	up  = vec3_norm(vec3_cross(coll->shape->pl.n, right));
	r.x = vec3_dot(v, right) / 64.0;
	r.y = vec3_dot(v, up) / 64.0;
	r.x -= (int)r.x;
	r.y -= (int)r.y;
	r.x = r.x * 0.5 + 0.5;
	r.y = r.y * 0.5 + 0.5;
	r.z = 0;
	return (r);
}

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
