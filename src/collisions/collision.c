/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collision.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 11:46:14 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 11:52:26 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"

t_collision	collision_none(void)
{
	return ((t_collision){.shape = NULL, .distance = INFINITY});
}

static t_collision	_collision(t_v3 point, t_shape *shape)
{
	return ((t_collision){.point = point, .shape = shape});
}

void	*collision_get_func(t_shape_type type)
{
	static const t_collfunc	f[] = {
	[SHAPE_NONE] = NULL,
	[SHAPE_PLANE] = collision_plane,
	[SHAPE_SQUARE] = NULL,
	[SHAPE_CIRCLE] = NULL,
	[SHAPE_TRIANGLE] = NULL,
	[SHAPE_SPHERE] = collision_sphere,
	[SHAPE_CYLINDER] = collision_cylinder
	};

	return (f[type]);
}
