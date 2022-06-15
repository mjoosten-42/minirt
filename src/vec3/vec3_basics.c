/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:15:30 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/15 14:36:55 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_v3	vec3(double x, double y, double z)
{
	return ((t_v3){x, y, z});
}

/* Also known as magnitude */
double	vec3_length(t_v3 vec3)
{
	return (sqrt(vec3.x * vec3.x + vec3.y * vec3.y + vec3.z * vec3.z));
}

t_v3	vec3_norm(t_v3 vec3)
{
	t_v3	normalized;
	double	length;

	length = vec3_length(vec3);
	normalized.x = vec3.x / length;
	normalized.y = vec3.y / length;
	normalized.z = vec3.z / length;
	return (normalized);
}

t_v3	vec3_dup(t_v3 vec3)
{
	return ((t_v3){vec3.x, vec3.y, vec3.z});
}

t_v3	vec3_inv(t_v3 vec3)
{
	return ((t_v3){-vec3.x, -vec3.y, -vec3.z});
}
