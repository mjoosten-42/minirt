/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray3.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:08:36 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/15 19:44:50 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec3.h"

# define INFINITY 1e300

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
