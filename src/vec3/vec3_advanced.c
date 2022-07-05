/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_advanced.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:06:03 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 11:43:17 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>
#include "equations.h"

//	Formula for mirroring a vector: 𝑟=𝑑−2(𝑑⋅𝑛)𝑛
t_v3	vec3_calc_reflection(t_v3 incoming, t_v3 normal)
{
	t_v3	refl;

	refl = vec3_norm(vec3_sub(incoming,
				vec3_mul(vec3_mul(normal, vec3_dot(incoming, normal)), 2)));
	return (refl);
}

// n1 * sin(angle1) = n2 * sin(angle2)
// sin(angle2) = n1 * sin(angle1) / n2
// angle = asin(n1 * sin(angle1) / n2)
t_v3	vec3_calc_refraction_m(t_v3 incoming, t_v3 normal, double n1, double n2)
{
	t_v3	refr;
	t_v3	axis;
	double	angle;

	angle = vec3_angle(incoming, normal);
	angle = asin(n1 / n2 * sin(angle));
	if (angle > asin(n2 / n1))
		return (vec3_calc_reflection(incoming, normal));
	axis = vec3_cross(incoming, normal);
	refr = rodrigues(incoming, axis, angle);
	return (refr);
}

//	Really weird "warping" refraction, but it kinda looks like glass
t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double strength)
{
	t_v3	refl;
	t_v3	out;
	double	angle;

	refl = vec3_calc_reflection(incoming, normal);
	angle = vec3_dot(refl, incoming);
	angle = clamp(angle, 0.0, 1.0);
	angle = pow(angle, strength);
	out = incoming;
	out.x += (out.x - refl.x) * angle;
	out.y += (out.y - refl.y) * angle;
	out.z += (out.z - refl.z) * angle;
	out = vec3_norm(out);
	return (out);
}

double	vec3_angle(t_v3 v1, t_v3 v2)
{
	return (acos(vec3_dot(v1, v2) / (vec3_length(v1) * vec3_length(v2))));
}

double	vec3_distance(t_v3 v1, t_v3 v2)
{
	return (vec3_length(vec3_sub(v1, v2)));
}

t_v3	vec3_project(t_v3 v1, t_v3 v2)
{
	return (vec3_mul(v2, vec3_dot(v1, v2) / vec3_dot(v2, v2)));
}
