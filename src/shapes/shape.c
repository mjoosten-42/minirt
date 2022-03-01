/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:22:20 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/01 12:41:39 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "utils.h"
#include "log.h"

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

void	*shape_get_coll_func(t_shape_type type)
{
	static const t_collfunc	f[] =
	{
		[SHAPE_NONE] = NULL,
		[SHAPE_PLANE] = NULL,
		[SHAPE_SQUARE] = NULL,
		[SHAPE_CIRCLE] = NULL,
		[SHAPE_TRIANGLE] = NULL,
		[SHAPE_SPHERE] = shape_sphere_collision
	};

	return (f[type]);
}
