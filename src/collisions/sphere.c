/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sphere.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 12:06:19 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/17 11:54:36 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "vec3.h"
#include "shape.h"
#include "shape_masks.h"
#include "equations.h"
#include <math.h>

t_collision	collision_sphere(const t_shape *sphere, const t_ray3 *ray)
{
	t_v3			len_vec;
	t_abc			values;
	double			t[2];
	t_collision		coll;

	len_vec = vec3_sub(ray->o, sphere->o);
	values.a = vec3_dot(ray->d, ray->d);
	values.b = 2.0 * vec3_dot(ray->d, len_vec);
	values.c = vec3_dot(len_vec, len_vec)
		- (sphere->sp.radius * sphere->sp.radius);
	if (quadratic(t, values) < 0 || t[0] < 0)
		return (collision_none());
	coll.shape = sphere;
	coll.point = ray_point(ray, t[0]);
	coll.normal = vec3_norm(vec3_sub(coll.point, sphere->o));
	if (vec3_distance(ray->o, sphere->o) < sphere->sp.radius)
		coll.normal = vec3_inv(coll.normal);
	coll.distance = t[0];
	return (coll);
}
