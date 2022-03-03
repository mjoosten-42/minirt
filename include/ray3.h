/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:08:36 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 11:32:24 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY3_H
# define RAY3_H

# include "vec3.h"
# include "list.h"

/**
**	A "unique" way to define Infinity for rays
*/
# define INFINITY 1e300

/**
**	Represents a 3-dimensional ray
**	@param origin <t_v3> Origin point of the ray
**	@param direction <t_v3> Normalized vector as direction
**	@param distance <double> Distance of the ray, usually Infinite at start
*/
typedef struct s_ray3
{
	t_v3	origin;
	t_v3	direction;
	double	distance;
}			t_ray3;

/* ray3.c */
t_ray3	ray3(t_v3 origin, t_v3 normalized_direction);

/* ray_debug.c */
void	ray_print(t_ray3 ray3);

#endif
