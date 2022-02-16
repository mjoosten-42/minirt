/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:22:20 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/16 13:57:24 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "utils.h"

t_shape	*shape_allocate(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (shape == NULL)
		return (NULL);
	ft_bzero(shape, sizeof(t_shape));
	return (shape);
}

t_shape	*shape_create(t_shape_type type, t_v3 origin, t_color col, void *mask)
{
	t_shape	*shape;

	shape = shape_allocate();
	if (shape == NULL)
		return (NULL);
	shape->type = type;
	shape->origin = origin;
	shape->color = col;
	shape->mask = mask;
	return (shape);
}
