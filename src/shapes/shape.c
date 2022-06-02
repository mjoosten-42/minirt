/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:22:20 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/02 14:56:38 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "log.h"
#include "../lib/libft/include/libft.h"

static t_material	_material_default(void)
{
	return ((t_material){.type = MATERIAL_DEFAULT, 0.0, 4.0});
}

static t_shape	*shape_allocate(void)
{
	t_shape	*shape;

	shape = malloc(sizeof(t_shape));
	if (shape == NULL)
	{
		LOG_ERR("Failed to allocate shape");
		return (NULL);
	}
	ft_bzero(shape, sizeof(t_shape));
	LOG("Allocated shape");
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
	shape->material = _material_default();
	shape->mask = mask;
	return (shape);
}

/*
**	Assumes it gets a t_shape struct
*/
void	shape_free(void *shape)
{
	free(((t_shape *)shape)->mask);
	LOG("Shape mask freed");
	free(shape);
	LOG("Shape freed");
}
