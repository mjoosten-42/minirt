/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_advanced.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:06:03 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/17 12:39:24 by ngerrets      ########   odam.nl         */
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

/*
inline void Refract(
  VEC3 &out, const VEC3 &incidentVec, const VEC3 &normal, float eta)
{
  float N_dot_I = Dot(normal, incidentVec);
  float k = 1.f - eta * eta * (1.f - N_dot_I * N_dot_I);
  if (k < 0.f)
    out = VEC3(0.f, 0.f, 0.f);
  else
    out = eta * incidentVec - (eta * N_dot_I + sqrtf(k)) * normal;
}
*/

t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double strength)
{
	double	dot;
	double	k;
	t_v3	refr;

	dot = vec3_dot(normal, incoming);
	k = 1.0 - strength * strength * (1.0 - dot * dot);
	if (k < 0.0)
		return (incoming);
	refr = vec3_sub(vec3_mul(incoming, strength), vec3_mul(normal, strength * dot * sqrt(k)));
	refr = vec3_norm(refr);
	return (refr);
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
