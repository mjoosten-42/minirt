/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:03:06 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/15 15:43:57 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# define VECTOR_DEBUG_PRINT_MESSAGE "VEC3: (%.3f, %.3f, %.3f)\n"

/**
**	Three dimensional vector/coordinate
**	@param x <double> Horizontal axis
**	@param y <double> Depth axis
**	@param z <double> Height axis
*/
typedef struct s_v3
{
	double	x;
	double	y;
	double	z;
}			t_v3;

/* vec3_basics.c */
t_v3	vec3(double x, double y, double z);
double	vec3_length(t_v3 vec3);
t_v3	vec3_norm(t_v3 vec3);
t_v3	vec3_dup(t_v3 vec3);
t_v3	vec3_inv(t_v3 vec3);

/* vec3_math.c */
double	vec3_dot(t_v3 v1, t_v3 v2);
t_v3	vec3_mul(t_v3 vec3, double length);
t_v3	vec3_cross(t_v3 v1, t_v3 v2);
t_v3	vec3_sub(t_v3 v1, t_v3 v2);
t_v3	vec3_add(t_v3 v1, t_v3 v2);

/* vec3_debug.c */
void	vec3_print(t_v3 vec3);

/* vec3_advanced.c */
t_v3	vec3_calc_reflection(t_v3 incoming, t_v3 normal);
double	vec3_angle(t_v3 v1, t_v3 v2);
double	vec3_distance(t_v3 v1, t_v3 v2);
t_v3	vec3_project(t_v3 v1, t_v3 v2);

#endif
