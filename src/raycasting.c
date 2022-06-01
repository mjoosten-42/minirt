/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:31 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/01 10:51:04 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "collision.h"
#include "log.h"
#include <math.h>

t_collision	collision_none(void)
{
	return ((t_collision){.shape = NULL, .distance = INFINITY});
}

static t_collision	_collision(t_v3 point, t_shape *shape)
{
	return ((t_collision){.point = point, .shape = shape});
}

t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray)
{
	t_shape		*current_shape;
	t_collfunc	f;
	t_collision	coll;
	t_collision	closest_collision;

	closest_collision = collision_none();
	if (shapes == NULL)
	{
		LOG_ERR("No shapes to check collision on");
		return (collision_none());
	}
	while (shapes != NULL)
	{
		current_shape = (t_shape *)shapes->content;
		if (current_shape == NULL)
		{
			LOG_ERR("Content == NULL");
			return (collision_none());
		}
		f = collision_get_func(current_shape->type);
		if (f != NULL)
		{
			coll = f(current_shape, ray);
			if (coll.shape != NULL)
				if (coll.distance < closest_collision.distance)
					closest_collision = coll;
		}
		shapes = shapes->next;
	}
	return (closest_collision);
}
