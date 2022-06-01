/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 16:11:54 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/01 17:04:07 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include "ray3.h"
#include "shape.h"
#include "shape_masks.h"

//(x - z)^2 + (z - x)^2 + (x - y)^2 = 3r^2


t_shape	*cylinder_dup(t_shape *cylinder);

t_collision	collision_cylinder(const t_shape *cylinder, const t_ray3 *ray)
{
	t_collision	coll;

	coll = collision_none();
	return (coll);
}

t_shape	*rotate_cylinder(t_shape *cylinder, t_v3 rotation)
{
	t_shape	*rotated;

	rotated = cylinder_dup(cylinder);
	return (rotated);
}

t_shape	*cylinder_dup(t_shape *cylinder)
{
	t_shape			*dup;
	t_mask_cylinder	*mask;

	dup = ft_malloc(sizeof(t_shape));
	mask = ft_malloc(sizeof(t_mask_cylinder));
	mask->normal = ((t_mask_cylinder *)cylinder->mask)->normal;
	mask->height = ((t_mask_cylinder *)cylinder->mask)->height;
	mask->diameter = ((t_mask_cylinder *)cylinder->mask)->diameter;
	dup->origin = cylinder->origin;
	dup->color = cylinder->color;
	dup->type = cylinder->type;
	dup->mask = mask;
	return (dup);
}