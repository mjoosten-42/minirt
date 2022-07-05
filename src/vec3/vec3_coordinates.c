/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_coordinates.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/05 14:52:24 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 17:38:45 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <math.h>

double	vec3_get_latitude(t_v3 v)
{
	double	lat;

	lat = atan2(v.y, (sqrt(v.x * v.x + v.z * v.z))) / M_PI_2;
	return (lat);
}


double	vec3_get_longitude(t_v3 v)
{
	return (atan(v.z / v.x) / M_PI_2);
}
