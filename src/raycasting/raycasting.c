/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:31 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/05 15:51:01 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "program.h"
#include <math.h>
#include "shape.h"
#include "raycasting.h"
#include "equations.h"
#include "color.h"

t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray)
{
	t_collision	coll;
	t_collision	closest_collision;

	closest_collision = collision_none();
	while (shapes != NULL)
	{
		coll = ((t_shape *)shapes->content)->f(shapes->content, ray);
		if (coll.shape != NULL)
			if (coll.distance < closest_collision.distance)
				closest_collision = coll;
		shapes = shapes->next;
	}
	return (closest_collision);
}

double	raycast_get_light_perc(t_list *shapes,
	const t_ray3 *ray,
	double max_dist)
{
	t_collision	coll;
	double		percent;

	percent = 1.0;
	while (shapes != NULL)
	{
		coll = ((t_shape *)shapes->content)->f(shapes->content, ray);
		if (coll.shape != NULL)
		{
			if (coll.distance < max_dist)
			{
				percent *= coll.shape->material.refraction;
				if (percent < __FLT_EPSILON__)
					return (0.0);
			}
		}
		shapes = shapes->next;
	}
	return (percent);
}

static t_color	calc_ambient(t_color c, const t_ambience *amb)
{
	c = color_mul(c, amb->color);
	color_luminosity(&c, amb->intensity);
	return (c);
}

t_color	raycast_calc_lighting(const t_program *program, t_collision coll)
{
	t_list	*list;
	t_color	c;

	c = calc_ambient(coll.shape->color, &(program->ambience));
	list = program->lights;
	while (list != NULL)
	{
		c = color_add(c, ray_to_light(program, coll, (t_light *)list->content));
		list = list->next;
	}
	return (c);
}

t_rdata	raycast(const t_program *program, const t_ray3 *ray)
{
	t_rdata	rdata;

	rdata.coll = raycast_get_collision(program->shapes, ray);
	if (rdata.coll.shape == NULL)
		return (rdata);
	rdata.color = material_cast(program, ray, rdata).color;
	return (rdata);
}
