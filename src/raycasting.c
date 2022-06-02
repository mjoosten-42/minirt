/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:44:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 12:36:03 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "collision.h"
#include "log.h"
#include "program.h"
#include <math.h>

#include "raycasting.h"

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

t_color	ray_to_light(t_program *program, t_collision coll)
{
	t_color		c;
	t_ray3		ray;
	t_collision	shadow_coll;
	t_light		*light;

	c = coll.shape->color;
	if (program->lights == NULL)
		return (color_f(0, 0, 0));
	shadow_coll = collision_none();
	light = (t_light *)program->lights->content;
	ray.origin = coll.point;
	ray.direction = vec3_sub(light->origin, coll.point);
	vec3_normalize(&ray.direction);
	ray.origin = vec3_add(ray.origin, vec3_mul(ray.direction, __FLT_EPSILON__));
	shadow_coll = raycast_get_collision(program->shapes, &ray);
	c = coll.shape->color;
	if (shadow_coll.shape != NULL && shadow_coll.distance < vec3_length(vec3_sub(light->origin, coll.point)))
	{
		color_luminosity(&c, program->ambience.intensity);
		return (c);
	}
	color_luminosity(&c, fmax(light->intensity, program->ambience.intensity));
	//float phong;
	//phong = 3.0 * vec3_dot(coll.normal, ray.direction);
	//color_luminosity(&c, fmax(phong, program->ambience.intensity));
	color_luminosity(&c, fmax(vec3_dot(coll.normal, ray.direction), program->ambience.intensity));
	return (c);
}

t_rdata	raycast(t_program *program, t_ray3 *ray)
{
	t_rdata			rdata;
	t_rdata			rdata2;
	t_material_type	mtype;
	t_rcastfunc		func;

	rdata.last_coll = raycast_get_collision(program->shapes, ray);
	if (rdata.last_coll.shape == NULL)
		return (rdata);
	mtype = rdata.last_coll.shape->material.type;
	if (ray->bounces >= RAY_MAX_BOUNCES)
		func = material_get_func(MATERIAL_DEFAULT);
	else
		func = material_get_func(rdata.last_coll.shape->material.type);
	rdata2 = func(program, ray, rdata);
	rdata.color = rdata2.color;
	return (rdata);
}
