/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 11:29:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 11:32:30 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_H
# define COLLISION_H

# include "vec3.h"
# include "shape.h"

/**
**	Collision data of ray intersecting a shape
**	@param point <t_v3> Point-Vector of world collision
**	@param shape <t_shape*> Shape that got collided with
*/
typedef struct s_collision
{
	t_v3	point;
	t_shape	*shape;
}			t_collision;

/* raycast.c */
t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray);

#endif
