/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:28:46 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/07 13:11:23 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "shape_masks.h"
#include "collision.h"
#include "ray3.h"

static t_shape	build_plane_from_circle(const t_shape *circle);

t_collision	collision_circle(const t_shape *circle, const t_ray3 *ray)
{
	t_collision	coll;
	t_shape		plane;

	plane = build_plane_from_circle(circle);
	coll = collision_plane(&plane, ray);
	if (coll.shape == NULL)
		return (collision_none());
	if (vec3_distance(coll.point, circle->origin) > circle->ci.radius)
		return (collision_none());
	coll.shape = circle;
	return (coll);
}

static t_shape	build_plane_from_circle(const t_shape *circle)
{
	t_shape	plane;

	plane.type = SHAPE_PLANE;
	plane.origin = circle->origin;
	plane.color = circle->color;
	plane.f = collision_plane;
	plane.pl.normal = circle->ci.normal;
	plane.material = circle->material;
	return (plane);
}