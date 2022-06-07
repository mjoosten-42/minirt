/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_advanced.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:06:03 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/07 14:02:55 by mjoosten         ###   ########.fr       */
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
