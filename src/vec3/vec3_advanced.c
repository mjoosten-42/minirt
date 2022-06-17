/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_advanced.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:06:03 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/17 15:03:48 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_v3	vec3_calc_reflection(t_v3 incoming, t_v3 normal)
{
	t_v3	refl;

	refl = vec3_sub(incoming,
			vec3_mul(vec3_mul(normal, vec3_dot(incoming, normal)), 2));
	return (refl);
}

//	Really weird "warping" refraction, but it looks like glass
t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double strength)
{
	t_v3	refl;
	t_v3	out;
	double	angle;

	refl = vec3_calc_reflection(incoming, normal);
	
	angle = vec3_dot(refl, incoming);
	if (angle > 1.0)
		angle = 1.0;
	else if (angle < 0.0)
		angle = 0.0;
	angle = pow(angle, 4.0);
	out = incoming;
	out.x += (out.x - refl.x) * angle;
	out.y += (out.y - refl.y) * angle;
	out.z += (out.z - refl.z) * angle;
	out = vec3_norm(out);
	return (out);
}

// t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double strength)
// {
// 	double	cosi;
// 	double	n1;
// 	double	n2;
// 	double	eta;
// 	double	k;
// 	t_v3	refr;

// 	cosi = vec3_dot(incoming, normal);
// 	if (cosi > 0.0f)
// 	{
// 		n1 = strength;
// 		n2 = 1.0;
// 		normal = vec3_inv(normal);
// 	}
// 	else
// 	{
// 		n1 = 1.0;
// 		n2 = strength;
// 		cosi = -cosi;
// 	}
// 	eta = n1 / n2;
// 	k = 1.0 - (eta * eta) * (1.0 - cosi * cosi);
// 	if (k < 0.0)
// 		refr = vec3_calc_reflection(incoming, normal);
// 	else
// 		refr = vec3_add( vec3_mul(incoming, eta), vec3_mul(normal, eta * cosi * sqrt(k)) );
// 	return (refr);
// }

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
