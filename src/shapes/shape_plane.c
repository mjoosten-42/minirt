/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_plane.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:51:48 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/01 12:09:09 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ray3.h"

t_mask_plane	shape_plane_mask(t_v3 normal)
{
	return ((t_mask_plane){normal});
}

int	shape_plane_collision(const t_shape *plane, const t_ray3 *ray)
{
	t_mask_plane	*mask;

	mask = (t_mask_plane *)plane->mask;
	return (0);
}
