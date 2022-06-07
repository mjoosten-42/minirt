/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/07 15:25:46 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/06/07 15:42:16 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "shape_masks.h"
#include "collision.h"
#include "ray3.h"

static t_shape	build_plane_from_triangle(const t_shape *triangle);

static int	point_is_in_triangle(const t_shape *triangle, t_v3 point)
{
	return (0);
}

t_collision	collision_triangle(const t_shape *triangle, const t_ray3 *ray)
{
	t_collision	coll;
	t_shape		plane;

	plane = build_plane_from_triangle(triangle);
	coll = collision_plane(&plane, ray);
	if (coll.shape == NULL)
		return (collision_none());
	if (!point_is_in_triangle(triangle, coll.point))
		return (collision_none());
	coll.shape = triangle;
	return (coll);
}

static t_shape	build_plane_from_triangle(const t_shape *triangle)
{
	t_shape	plane;

	plane.type = SHAPE_PLANE;
	plane.origin = triangle->origin;
	plane.color = triangle->color;
	plane.f = collision_plane;
	plane.pl.normal = triangle->tr.normal;
	plane.material = triangle->material;
	return (plane);
}
