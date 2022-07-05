/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_lighting.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 15:02:46 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/04 16:44:46 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include <math.h>
#include "equations.h"

static t_ray3	_calc_lightray(const t_light *light, const t_collision *coll)
{
	t_ray3	ray;

	ray.o = coll->point;
	ray.d = vec3_norm(vec3_sub(light->o, coll->point));
	ray.o = vec3_add(ray.o, vec3_mul(ray.d, __FLT_EPSILON__));
	return (ray);
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

	if (!ENABLE_SPECULAR)
		return ((t_color){0, 0, 0});
	c = light->color;
	refl = vec3_calc_reflection(ray->d, coll->normal);
	to_cam = vec3_mul(ray->d, -1);
	angle = vec3_dot(refl, to_cam);
	angle = clamp(angle, 0.0, 1.0);
	angle = pow(angle, shine);
	color_luminosity(&c, angle * light->intensity);
	return (c);
}

t_color	ray_to_light(const t_program *program,
	t_collision coll,
	const t_light *light)
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
		return ((t_color){0, 0, 0});
	diffuse_c = _calc_diffuse(&coll, light, &ray);
	specular_c = _calc_specular(&coll, light, &ray, coll.shape->material.shine);
	total_c = color_add(specular_c, diffuse_c);
	color_luminosity(&total_c, light_percent);
	return (total_c);
}
