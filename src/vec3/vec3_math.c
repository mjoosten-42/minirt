/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:20:35 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 11:39:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

double	vec3_dot(t_v3 v1, t_v3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_v3	vec3_mul(t_v3 vec3, double length)
{
	return ((t_v3){vec3.x * length, vec3.y * length, vec3.z * length});
}

t_v3	vec3_cross(t_v3 v1, t_v3 v2)
{
	return ((t_v3){v1.y * v2.z - v1.z * v2.y,
		-(v1.x * v2.z - v1.z * v2.x),
		v1.x * v2.y - v1.y * v2.x});
}

t_v3	vec3_sub(t_v3 v1, t_v3 v2)
{
	return ((t_v3){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_v3	vec3_add(t_v3 v1, t_v3 v2)
{
	return ((t_v3){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}
