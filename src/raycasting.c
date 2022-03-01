/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycasting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:44:31 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/01 12:38:43 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "shape.h"
#include "list.h"
#include "log.h"



int	raycast_check_collision(t_list *shapes, const t_ray3 *ray)
{
	t_shape	*current_shape;
	t_collfunc	f;

	if (shapes == NULL)
	{
		LOG_ERR("No shapes to check collision on");
		return (0);
	}
	while (shapes != NULL)
	{
		current_shape = (t_shape *)shapes->content;
		if (current_shape == NULL)
		{
			LOG_ERR("Content == NULL");
			return (0);
		}
		f = shape_get_coll_func(current_shape->type);
		if (f != NULL && f(current_shape, ray) > 0)
			return (1);
		shapes = shapes->next;
	}
	return (0);
}
