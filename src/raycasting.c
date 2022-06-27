/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:44:31 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/27 16:05:42 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "program.h"
#include <math.h>
#include "shape.h"
#include "raycasting.h"

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

t_collision	raycast_get_coll_ignore_refr(t_list *shapes, const t_ray3 *ray)
{
	t_collision	coll;
	t_collision	closest_collision;

	closest_collision = collision_none();
	while (shapes != NULL)
	{
		coll = ((t_shape *)shapes->content)->f(shapes->content, ray);
		if (coll.shape != NULL && coll.shape->material.refraction == 0.0)
			if (coll.distance < closest_collision.distance)
				closest_collision = coll;
		shapes = shapes->next;
	}
	return (closest_collision);
}

double	raycast_get_light_perc(t_list *shapes, const t_ray3 *ray, double max_dist)
{
	t_collision	coll;
	double		percent;

	percent = 1.0;
	while (shapes != NULL)
	{
		coll = ((t_shape *)shapes->content)->f(shapes->content, ray);
		if (coll.shape != NULL)
			if (coll.distance < max_dist)
			{
				percent *= coll.shape->material.refraction;
				if (percent < __FLT_EPSILON__)
					return (0.0);
			}
		shapes = shapes->next;
	}
	return (percent);
}

static t_ray3	_calc_lightray(const t_light *light, const t_collision *coll)
{
	t_ray3	ray;

	ray.o = coll->point;
	ray.d = vec3_norm(vec3_sub(light->o, coll->point));
	ray.o = vec3_add(ray.o, vec3_mul(ray.d, __FLT_EPSILON__));
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
	color_luminosity(&c, vec3_dot(ray->d, coll->normal) * light->intensity);
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
	refl = vec3_calc_reflection(ray->d, coll->normal);

	to_cam = vec3_mul(ray->d, -1);
	
	angle = vec3_dot(refl, to_cam);
	if (angle > 1.0)
		angle = 1.0;
	if (angle < 0.0)
		angle = 0.0;
	angle = pow(angle, shine);
	color_luminosity(&c, angle * light->intensity);
	return (c);
}

static t_color	ray_to_light(const t_program *program, t_collision coll, const t_light *light)
{
	t_color		diffuse_c;
	t_color		specular_c;
	t_color		total_c;
	t_ray3		ray;
	double		light_percent;

	ray = _calc_lightray(light, &coll);
	light_percent = raycast_get_light_perc(program->shapes, &ray,
		vec3_distance(light->o, coll.point));
	if (light_percent < __FLT_EPSILON__)
		return (color_f(0, 0, 0));
	diffuse_c = _calc_diffuse(&coll, light, &ray);
	specular_c = _calc_specular(&coll, light, &ray, coll.shape->material.shine);
	total_c = color_add(specular_c, diffuse_c);
	color_luminosity(&total_c, light_percent);
	return (total_c);
}

t_color	raycast_calc_lighting(const t_program *program, t_collision coll)
{
	t_list	*list;
	t_color	c;

	c = _calc_ambient(coll.shape->color, &(program->ambience));
	list = program->lights;
	while (list != NULL)
	{
		c = color_add(c, ray_to_light(program, coll, (t_light *)list->content));
		list = list->next;
	}
	return (c);
}

t_rdata	material_cast(const t_program *program, t_ray3 *ray, t_rdata rdata);

t_rdata	raycast(const t_program *program, t_ray3 *ray)
{
	t_rdata	rdata;

	rdata.last_coll = raycast_get_collision(program->shapes, ray);
	if (rdata.last_coll.shape == NULL)
		return (rdata);
	rdata.color = material_cast(program, ray, rdata).color;
	return (rdata);
}
