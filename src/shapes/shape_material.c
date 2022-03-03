/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_material.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/03 12:22:00 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 12:26:20 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"

int	shape_is_default_material(t_shape *shape)
{
	if (shape->material.type == MATERIAL_DEFAULT)
		return (1);
	return (0);
}
