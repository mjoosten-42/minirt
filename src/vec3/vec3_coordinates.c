/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 14:52:24 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 11:44:07 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

double	vec3_get_latitude(t_v3 v)
{
	return (atan2(v.y, (sqrt(v.x * v.x + v.z * v.z))) / M_PI_2);
}

double	vec3_get_longitude(t_v3 v)
{
	return (atan(v.z / v.x) / M_PI_2);
}
