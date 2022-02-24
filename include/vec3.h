/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:03:06 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/16 12:35:34 by ngerrets      ########   odam.nl         */
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
void	vec3_normalize(t_v3 *vec3);
t_v3	vec3_dup(t_v3 vec3);

/* vec3_math.c */
double	vec3_dot(t_v3 v1, t_v3 v2);
void	vec3_mul(t_v3 *vec3, double length);
t_v3	vec3_cross(t_v3 v1, t_v3 v2);

/* vec3_debug.c */
void	vec3_print(t_v3 vec3);

#endif
