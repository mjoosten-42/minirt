/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:31 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/01 14:20:08 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "collision.h"
#include "log.h"
#include "program.h"
#include <math.h>

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
	static const t_collfunc	f[] =
	{
		[SHAPE_NONE] = NULL,
		[SHAPE_PLANE] = collision_plane,
		[SHAPE_SQUARE] = NULL,
		[SHAPE_CIRCLE] = NULL,
		[SHAPE_TRIANGLE] = NULL,
		[SHAPE_SPHERE] = collision_sphere,
		[SHAPE_CYLINDER] = NULL
	};

	return (f[type]);
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

void	ray_to_light(t_program *program, t_collision coll, t_color *c)
{
	t_ray3		ray;
	t_collision	shadow_coll;

	if (program->lights == NULL)
	{
		*c = (t_color){0, 0, 0};
		return ;
	}
	shadow_coll = collision_none();
	ray = ray3(coll.point, vec3_sub(((t_light *)program->lights->content)->origin, coll.point));
	ray.origin = vec3_add(ray.origin, vec3_mul(ray.direction, __FLT_EPSILON__));
	shadow_coll = raycast_get_collision(program->shapes, &ray);
	if (shadow_coll.shape == NULL)
	{
		color_luminosity(c, ((t_light *)program->lights->content)->intensity);
	}
	else
	{
		*c = (t_color){0, 0, 0};
	}
}
