/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:03:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 14:55:59 by ngerrets      ########   odam.nl         */
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
t_v3	vec3_calc_refraction(t_v3 incoming, t_v3 normal, double strength);
double	vec3_angle(t_v3 v1, t_v3 v2);
double	vec3_distance(t_v3 v1, t_v3 v2);
t_v3	vec3_project(t_v3 v1, t_v3 v2);

t_v3	vec3_calc_refraction_m(t_v3 incoming,
			t_v3 normal,
			double n1,
			double n2);

/* vec3_coordinates.c */
double	vec3_get_latitude(t_v3 v);
double	vec3_get_longitude(t_v3 v);

#endif
