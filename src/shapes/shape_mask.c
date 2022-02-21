/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_mask.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:35:19 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 19:32:30 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "utils.h"
#include "log.h"

/*
**	Cheeky way to get sizeof :)
*/
static size_t	_get_size(t_shape_type type)
{
	size_t	size;

	size = 0;
	size += (type == SHAPE_PLANE) * sizeof(t_mask_plane);
	size += (type == SHAPE_SQUARE) * sizeof(t_mask_square);
	size += (type == SHAPE_CIRCLE) * sizeof(t_mask_circle);
	return (size);
}

static void	*shape_mask_allocate(t_shape_type type)
{
	size_t	size;
	void	*mask;

	size = _get_size(type);
	if (size == 0)
	{
		LOG_ERR("Shape type unrecognized");
		return (NULL);
	}
	mask = malloc(size);
	if (mask == NULL)
	{
		LOG_ERR("Failed to allocate shape mask");
		return (NULL);
	}
	LOG("Allocated shape mask");
	return (mask);
}

void	*shape_mask(t_shape_type type, void *data)
{
	void	*mask;

	mask = shape_mask_allocate(type);
	if (mask == NULL)
		return (NULL);
	ft_memcpy(mask, data, _get_size(type));
	LOG("Copied shape mask data onto mask");
	return (mask);
}
