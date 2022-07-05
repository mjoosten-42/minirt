/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_lighting.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 15:02:46 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 19:12:10 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "raycasting.h"
#include "equations.h"

t_color	get_color(const t_collision *coll)
{
	t_color	c;
	t_v3	normal;

	c = coll->shape->color;
	if (coll->shape->material.checkerboard)
	{
		normal = vec3_norm(vec3_sub(coll->shape->o, coll->point));
		c = checkerboard_color(normal);
		c = color_mul(c, coll->shape->color);
	}
	else if (coll->shape->texture)
	{
		normal = vec3_norm(vec3_sub(coll->shape->o, coll->point));

		double x = vec3_get_longitude(normal) * 0.5 + 0.5;
		double y = vec3_get_latitude(normal) * 0.5 + 0.5;
		//printf("LON: %.3f | LAT: %.3f\n", x, y);
		c = texture_get_color(coll->shape->texture, x, y);
		c = color_mul(c, coll->shape->color);
	}
	return (c);
}

static t_ray3	calc_lightray(const t_light *light, const t_collision *coll)
{
	t_ray3	ray;

	ray.o = coll->point;
	ray.d = vec3_norm(vec3_sub(light->o, coll->point));
	ray.o = vec3_add(ray.o, vec3_mul(ray.d, __FLT_EPSILON__));
	return (ray);
}

static t_color	calc_diffuse(const t_collision *coll,
	const t_light *light, const t_ray3 *ray)
{
	t_color	c;

	c = get_color(coll);
	c = color_mul(light->color, c);
	color_luminosity(&c, vec3_dot(ray->d, coll->normal) * light->intensity);
	return (c);
}

static t_color	calc_specular(const t_collision *coll,
	const t_light *light, const t_ray3 *ray)
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
	angle = pow(angle, coll->shape->material.specular_index);
	color_luminosity(&c, angle * light->intensity * coll->shape->material.shine);
	return (c);
}

t_color	ray_to_light(const t_program *program,
	t_collision coll,
	const t_light *light)
{
	t_color		diffuse;
	t_color		specular;
	t_color		total;
	t_ray3		ray;
	double		light_percent;

	ray = calc_lightray(light, &coll);
	light_percent = raycast_get_light_perc(program->shapes, &ray,
			vec3_distance(light->o, coll.point));
	if (light_percent < __FLT_EPSILON__)
		return ((t_color){0, 0, 0});
	diffuse = calc_diffuse(&coll, light, &ray);
	specular = calc_specular(&coll, light, &ray);
	total = color_add(specular, diffuse);
	color_luminosity(&total, light_percent);
	return (total);
}
