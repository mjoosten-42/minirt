/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_advanced.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 14:06:03 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 14:10:45 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"

t_v3	vec3_calc_reflection(t_v3 incoming, t_v3 normal)
{
	t_v3	refl;

	refl = vec3_sub(incoming,
		vec3_mul(vec3_mul(normal, vec3_dot(incoming, normal)), 2));
	return (refl);
}