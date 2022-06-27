/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:50:42 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/27 16:15:09 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "material.h"
#include "raycasting.h"
#include "shape.h"
#include "vec3.h"

t_rdata	material_cast(const t_program *program, t_ray3 *ray, t_rdata rdata)
{
	t_ray3	mray;
	t_rdata new_rd;

	rdata.color = raycast_calc_lighting(program, rdata.last_coll);
	if (ray->bounces >= RAY_MAX_BOUNCES)
		return (rdata);
	if (rdata.last_coll.shape->material.reflection > 0)
	{
		mray.o = rdata.last_coll.point;
		mray.d = vec3_calc_reflection(ray->d, rdata.last_coll.normal);
		mray.o = vec3_add(mray.o, vec3_mul(rdata.last_coll.normal, __FLT_EPSILON__));
		mray.bounces = ray->bounces + 1;
		new_rd = raycast(program, &mray);
		if (new_rd.last_coll.shape == NULL)
			new_rd.color = color_f(0, 0, 0);
		rdata.color = color_blend(rdata.color,
			new_rd.color, rdata.last_coll.shape->material.reflection);
	}
	if (rdata.last_coll.shape->material.refraction > 0)
	{
		mray.o = rdata.last_coll.point;
		mray.d = vec3_calc_refraction(ray->d, rdata.last_coll.normal,
			rdata.last_coll.shape->material.index);
		mray.o = vec3_add(mray.o, vec3_mul(ray->d, __FLT_EPSILON__));
		mray.bounces = ray->bounces + 1;
		mray.index = rdata.last_coll.shape->material.index;
		new_rd = raycast(program, &mray);
		if (new_rd.last_coll.shape == NULL)
			new_rd.color = color_f(0, 0, 0);
		rdata.color = color_blend(rdata.color,
			new_rd.color, rdata.last_coll.shape->material.refraction);
	}
	return (rdata);
}
