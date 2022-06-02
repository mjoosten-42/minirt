/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_material.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 11:50:42 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 15:50:18 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "raycasting.h"

t_rdata	material_cast_default(t_program *program, t_ray3 *ray, t_rdata rdata)
{
	(void)ray;
	rdata.color = raycast_calc_lighting(program, rdata.last_coll);
	return (rdata);
}

//	Formala for mirroring a vector: 𝑟=𝑑−2(𝑑⋅𝑛)𝑛
t_rdata	material_cast_mirror(t_program *program, t_ray3 *ray, t_rdata rdata)
{
	t_ray3	mirrored_ray;
	t_rdata new_rd;

	mirrored_ray.origin = rdata.last_coll.point;
	mirrored_ray.direction = vec3_calc_reflection(ray->direction, rdata.last_coll.normal);
	mirrored_ray.origin = vec3_add(mirrored_ray.origin, vec3_mul(mirrored_ray.direction, __FLT_EPSILON__));
	mirrored_ray.bounces = ray->bounces + 1;
	new_rd = raycast(program, &mirrored_ray);
	rdata.color = color_blend(raycast_calc_lighting(program, rdata.last_coll), new_rd.color, rdata.last_coll.shape->material.reflection);
	return (rdata);
}

void	*material_get_func(t_material_type type)
{
	static const t_rcastfunc	f[] = {
	[MATERIAL_DEFAULT] = material_cast_default,
	[MATERIAL_MIRROR] = material_cast_mirror
	};

	return (f[type]);
}
