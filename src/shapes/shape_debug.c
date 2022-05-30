/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/05/30 10:55:10 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stdio.h>

static void	_shape_print_mask(t_shape *shape)
{
	if (shape->mask == NULL)
	{
		printf("|  |  NULL MASK\n");
		return ;
	}
	if (shape->type == SHAPE_PLANE)
	{
		printf("|  |  normal ");
		vec3_print(((t_mask_plane *)shape->mask)->normal);
	}
	if (shape->type == SHAPE_SQUARE)
	{
		printf("|  |  normal ");
		vec3_print(((t_mask_square *)shape->mask)->normal);
		printf("|  |  width: %.3f\n", ((t_mask_square *)shape->mask)->width);
	}
	if (shape->type == SHAPE_CIRCLE)
	{
		printf("|  |  normal ");
		vec3_print(((t_mask_circle *)shape->mask)->normal);
		printf("|  |  radius: %.3f\n", ((t_mask_circle *)shape->mask)->radius);
	}
	if (shape->type == SHAPE_SPHERE)
		printf("|  |  radius: %.3f\n", ((t_mask_sphere *)shape->mask)->radius);
}

void	shape_print(t_shape *shape)
{
	char	*shape_names[] = {
	"NONE",
	"PLANE",
	"SQUARE",
	"CIRCLE",
	"TRIANGLE",
	"SPHERE"
	};

	printf("# - SHAPE - - - - - - - - - - - - - - - -\n");
	printf("|  type %s\n", shape_names[shape->type]);
	printf("|  origin ");
	vec3_print(shape->origin);
	printf("|  color ");
	color_print_f(shape->color);
	printf("|  MASK:\n");
	_shape_print_mask(shape);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
