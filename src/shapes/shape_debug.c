/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_debug.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:51:29 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 12:31:15 by ngerrets      ########   odam.nl         */
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
	printf("# - SHAPE - - - - - - - - - - - - - - - -\n");
	printf("|  type %d\n", shape->type);
	printf("|  origin ");
	vec3_print(shape->origin);
	printf("|  color ");
	color_print_f(shape->color);
	printf("|  MASK:\n");
	_shape_print_mask(shape);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
