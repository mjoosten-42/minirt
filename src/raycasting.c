/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:44:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 11:39:15 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "collision.h"
#include "log.h"

static t_collision	_null_collision(void)
{
	return ((t_collision){.shape = NULL});
}

static t_collision	_collision(t_v3 point, t_shape *shape)
{
	return ((t_collision){.point = point, .shape = shape});
}

t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray)
{
	t_shape		*current_shape;
	t_collfunc	f;

	if (shapes == NULL)
	{
		LOG_ERR("No shapes to check collision on");
		return (_null_collision());
	}
	while (shapes != NULL)
	{
		current_shape = (t_shape *)shapes->content;
		if (current_shape == NULL)
		{
			LOG_ERR("Content == NULL");
			return (_null_collision());
		}
		f = shape_get_coll_func(current_shape->type);
		if (f != NULL && f(current_shape, ray) > 0)
			return (_collision(vec3(0, 0, 0), current_shape));
		shapes = shapes->next;
	}
	return (_null_collision());
}
