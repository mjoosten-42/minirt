/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:51:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/07 15:32:48 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include <stdio.h>

static void	_shape_print_mask(t_shape *shape)
{
	if (shape->type == SHAPE_PLANE)
	{
		printf("|  |  normal ");
		vec3_print(shape->pl.normal);
	}
	if (shape->type == SHAPE_SQUARE)
	{
		printf("|  |  normal ");
		vec3_print(shape->sq.normal);
		printf("|  |  width: %.3f\n", shape->sq.width);
	}
	if (shape->type == SHAPE_CIRCLE)
	{
		printf("|  |  normal ");
		vec3_print(shape->ci.normal);
		printf("|  |  radius: %.3f\n", shape->ci.radius);
	}
	if (shape->type == SHAPE_TRIANGLE)
	{
		printf("|  |  point2 ");
		vec3_print(shape->tr.point2);
		printf("|  |  point3 ");
		vec3_print(shape->tr.point3);
		printf("|  |  normal ");
		vec3_print(shape->tr.normal);
	}
	if (shape->type == SHAPE_SPHERE)
		printf("|  |  radius: %.3f\n", shape->sp.radius);
	if (shape->type == SHAPE_CYLINDER)
	{
		printf("|  |  normal ");
		vec3_print(shape->cy.normal);
		printf("|  |  radius: %.3f\n", shape->cy.radius);
		printf("|  |  height: %.3f\n", shape->cy.height);
	}
}

void	shape_print(t_shape *shape)
{
	char	*shape_names[] = {
	"NONE",
	"PLANE",
	"SQUARE",
	"CIRCLE",
	"TRIANGLE",
	"SPHERE",
	"CYLINDER"
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
