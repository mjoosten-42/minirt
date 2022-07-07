/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:06:03 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 11:21:56 by mjoosten         ###   ########.fr       */
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

t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double n1, double n2)
{
	t_v3	refr;
	t_v3	axis;
	double	incident;
	double	refraction;

	if (n1 != 1.0)
		n2 = 1.0;
	incident = vec3_angle(incoming, vec3_mul(normal, -1.0));
	refraction = n1 / n2 * sin(incident);
	if (refraction > 1.0)
		return (vec3_calc_reflection(incoming, normal));
	refraction = asin(refraction);
	axis = vec3_norm(vec3_cross(incoming, normal));
	refr = vec3_norm(rodrigues(incoming, axis, refraction - incident));
	return (refr);
}
