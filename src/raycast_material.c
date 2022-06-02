/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_material.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 11:50:42 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 12:37:57 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "raycasting.h"

t_rdata	material_cast_default(t_program *program, t_ray3 *ray, t_rdata rdata)
{
	(void)ray;
	rdata.color = ray_to_light(program, rdata.last_coll);
	return (rdata);
}

//	Formala for mirroring a vector: 𝑟=𝑑−2(𝑑⋅𝑛)𝑛
t_rdata	material_cast_mirror(t_program *program, t_ray3 *ray, t_rdata rdata)
{
	t_ray3	new_ray;

	new_ray.origin = rdata.last_coll.point;
	new_ray.direction = vec3_sub(ray->direction, vec3_mul(vec3_mul(rdata.last_coll.normal, vec3_dot(ray->direction, rdata.last_coll.normal)), 2));
	new_ray.origin = vec3_add(new_ray.origin, vec3_mul(new_ray.direction, __FLT_EPSILON__));
	new_ray.bounces = ray->bounces + 1;
	t_rdata new_rd = raycast(program, &new_ray);
	rdata.color = color_blend(ray_to_light(program, rdata.last_coll), new_rd.color, rdata.last_coll.shape->material.reflection);
	//rdata.color = new_rd.color;
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
