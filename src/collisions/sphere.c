/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:06:19 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/09 16:38:44 by mjoosten         ###   ########.fr       */
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

	len_vec = vec3_sub(ray->origin, sphere->origin);
	values.a = vec3_dot(ray->direction, ray->direction);
	values.b = 2.0 * vec3_dot(ray->direction, len_vec);
	values.c = vec3_dot(len_vec, len_vec)
		- (sphere->sp.radius * sphere->sp.radius);
	if (quadratic(t, values) < 0 || t[0] < 0)
		return (collision_none());
	coll.shape = sphere;
	coll.point = ray_point(ray, t[0]);
	coll.normal = vec3_sub(coll.point, sphere->origin);
	vec3_normalize(&(coll.normal));
	coll.distance = t[0];
	return (coll);
}
