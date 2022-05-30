/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:49:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/30 15:44:46 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "shape_masks.h"
#include "parse.h"

void	*get_ambience(char **strs)
{
	return (NULL);
}

void	*get_camera(char **strs)
{
	return (NULL);
}

void	*get_light(char **strs)
{
	return (NULL);
}

void	*get_sphere(char **strs)
{
	t_mask_sphere	*sphere;

	sphere = ft_malloc(sizeof(t_mask_sphere));
	sphere->radius = atod(strs[2]);
	return (sphere);
}

void	*get_plane(char **strs)
{
	t_mask_plane	*plane;

	plane = ft_malloc(sizeof(t_mask_plane));
	plane->normal = parse_vector_norm(strs[2]);
	return (plane);
}

void	*get_cylinder(char **strs)
{
	t_mask_cylinder	*cylinder;

	cylinder = ft_malloc(sizeof(t_mask_cylinder));
	cylinder->normal = parse_vector_norm(strs[2]);
	cylinder->diameter = atod(strs[3]);
	cylinder->height = atod(strs[4]);
	return (cylinder);
}
