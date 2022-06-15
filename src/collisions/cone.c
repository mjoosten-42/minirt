/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:40:22 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/15 16:12:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "shape.h"
#include "shape_masks.h"
#include "ray3.h"
#include "vec3.h"
#include "equations.h"

/* https://www.geometrictools.com/Documentation/IntersectionLineCone.pdf
** https://www.shadertoy.com/view/MtcXWr
**   normalize(cp * dot(s.v, cp) / dot(cp, cp) - s.v);
** https://stackoverflow.com/questions/66343772/cone-normal-vector
*/

t_collision	collision_cone(const t_shape *cone, const t_ray3 *ray)
{
	t_collision	coll;
	t_abc		abc;
	t_v3		co;
	t_v3		cp;
	double		t[2];
	double		h;
	double		a;

	a = cos(cone->co.angle) * cos(cone->co.angle);
	co = vec3_sub(ray->o, cone->o);
	abc.a = vec3_dot(ray->d, cone->n) * vec3_dot(ray->d, cone->n) - a;
	abc.b = 2 * (vec3_dot(ray->d, cone->n) * vec3_dot(co, cone->n)
		- vec3_dot(ray->d, co) * a);
	abc.c = vec3_dot(co, cone->n) * vec3_dot(co, cone->n)
		- vec3_dot(co, co) * a;
	if (quadratic(t, abc) < 0 || t[0] < 0)
		return (collision_none());
	coll.point = ray_point(ray, t[0]);
	h = vec3_dot(vec3_sub(coll.point, cone->o), cone->n);
	if (h < 0 || h > cone->co.height)
		return (collision_none());
	coll.distance = t[0];
	cp = vec3_sub(coll.point, cone->o);
	coll.normal = vec3_norm(vec3_sub(vec3_mul(cp, vec3_dot(cone->n, cp), cone->o));
	coll.shape = cone;
	return (coll);
}
