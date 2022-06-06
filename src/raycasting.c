/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:31 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/06 15:29:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "collision.h"
#include "log.h"
#include "program.h"
#include <math.h>
#include "shape.h"

#include "raycasting.h"

t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray)
{
	t_shape		*current_shape;
	t_collision	coll;
	t_collision	closest_collision;

	closest_collision = collision_none();
	if (shapes == NULL)
	{
		LOG_ERR("No shapes to check collision on");
		exit(EXIT_FAILURE);
	}
	while (shapes != NULL)
	{
		current_shape = (t_shape *)shapes->content;
		if (current_shape == NULL)
		{
			LOG_ERR("Content == NULL");
			return (collision_none());
		}
		coll = current_shape->f(current_shape, ray);
		if (coll.shape != NULL)
			if (coll.distance < closest_collision.distance)
				closest_collision = coll;
		shapes = shapes->next;
	}
	return (closest_collision);
}

static t_ray3	_calc_lightray(const t_light *light, const t_collision *coll)
{
	t_ray3	ray;

	ray.origin = coll->point;
	ray.direction = vec3_sub(light->origin, coll->point);
	vec3_normalize(&ray.direction);
	ray.origin = vec3_add(ray.origin, vec3_mul(ray.direction, __FLT_EPSILON__));
	return (ray);
}

static t_color	_calc_ambient(t_color c, const t_ambience *amb)
{
	c = color_mul(c, amb->color);
	color_luminosity(&c, amb->intensity);
	return (c);
}

static t_color	_calc_diffuse(const t_collision *coll,
	const t_light *light, const t_ray3 *ray)
{
	t_color	c;

	c = color_mul(light->color, coll->shape->color);
	color_luminosity(&c, vec3_dot(ray->direction, coll->normal) * light->intensity);
	return (c);
}

static t_color	_calc_specular(const t_collision *coll,
	const t_light *light, const t_ray3 *ray, double shine)
{
	t_color	c;
	t_v3	refl;
	t_v3	to_cam;
	double	angle;

	c = light->color;
	refl = vec3_calc_reflection(ray->direction, coll->normal);

	to_cam = vec3_mul(ray->direction, -1);
	
	angle = vec3_dot(refl, to_cam);
	if (angle > 1.0)
		angle = 1.0;
	if (angle < 0.0)
		angle = 0.0;
	angle = pow(angle, shine);
	color_luminosity(&c, angle * light->intensity);
	return (c);
}

static t_color	ray_to_light(t_program *program, t_collision coll, const t_light *light)
{
	t_color		diffuse_c;
	t_color		specular_c;
	t_ray3		ray;
	t_collision	shadow_coll;

	ray = _calc_lightray(light, &coll);
	shadow_coll = raycast_get_collision(program->shapes, &ray);
	if (shadow_coll.shape != NULL && shadow_coll.distance < vec3_length(vec3_sub(light->origin, coll.point)))
		return (color_f(0, 0, 0));
	diffuse_c = _calc_diffuse(&coll, light, &ray);
	specular_c = _calc_specular(&coll, light, &ray, coll.shape->material.shine);
	return (color_add(specular_c, diffuse_c));
}

t_color	raycast_calc_lighting(t_program *program, t_collision coll)
{
	float	ratio;
	t_list	*list;
	t_color	c;

	c = _calc_ambient(coll.shape->color, &(program->ambience));
	if (program->lights_amount == 0)
		return (c);
	ratio = 1.0 / (float)program->lights_amount;
	list = program->lights;
	while (list != NULL)
	{
		c = color_add(c, ray_to_light(program, coll, (t_light *)list->content));
		list = list->next;
	}
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
