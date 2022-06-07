/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodriguez.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:09:16 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/07 10:47:09 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

t_v3	rodrigues(t_v3 v, t_v3 axis, double angle)
{
	t_v3	t1;
	t_v3	t2;
	t_v3	t3;

	if (angle == 0 || angle == M_PI)
		return (v);
	t1 = vec3_mul(v, cos(angle));
	t2 = vec3_mul(vec3_cross(axis, v), sin(angle));
	t3 = vec3_mul(vec3_mul(axis, vec3_dot(axis, v)), 1 - cos(angle));
	return (vec3_add(vec3_add(t1, t2), t3));
}
