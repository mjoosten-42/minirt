/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:32:21 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/17 15:57:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"

t_ray3	ray3(t_v3 origin, t_v3 normalized_direction)
{
	return ((t_ray3){origin, normalized_direction, 0, 1});
}

t_v3	ray_point(const t_ray3 *ray, double t)
{
	return (vec3_add(ray->o, vec3_mul(ray->d, t)));
}
