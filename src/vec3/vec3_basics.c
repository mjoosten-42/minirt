/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:15:30 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/01 13:08:59 by mjoosten         ###   ########.fr       */
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

void	vec3_normalize(t_v3 *vec3)
{
	double	length;

	length = vec3_length(*vec3);
	vec3->x /= length;
	vec3->y /= length;
	vec3->z /= length;
}

t_v3	vec3_dup(t_v3 vec3)
{
	return ((t_v3){vec3.x, vec3.y, vec3.z});
}

t_v3	vec3_inv(t_v3 vec3)
{
	return ((t_v3){-vec3.x, -vec3.y, -vec3.z});
}
