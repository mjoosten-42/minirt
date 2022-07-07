/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:15:30 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 11:33:29 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_v3	vec3_norm(t_v3 v)
{
	return (vec3_mul(v, 1.0 / vec3_length(v)));
}

t_v3	vec3_project(t_v3 v1, t_v3 v2)
{
	return (vec3_mul(v2, vec3_dot(v1, v2) / vec3_dot(v2, v2)));
}

/* Also known as magnitude */
double	vec3_length(t_v3 vec3)
{
	return (sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z));
}

double	vec3_angle(t_v3 v1, t_v3 v2)
{
	return (acos(vec3_dot(v1, v2) / (vec3_length(v1) * vec3_length(v2))));
}

double	vec3_distance(t_v3 v1, t_v3 v2)
{
	return (vec3_length(vec3_sub(v1, v2)));
}
