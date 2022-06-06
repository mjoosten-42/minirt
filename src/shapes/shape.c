/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:55:37 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 12:00:24 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "parse.h"
#include "vec3.h"
#include "libft.h"

static t_shape	*build_shape(char **args, t_shape_type type)
{
	t_shape	*shape;

	shape = ft_malloc(sizeof(t_shape));
	shape->type = type;
	shape->material = (t_material){MATERIAL_DEFAULT, 0.1, 1.0};
	shape->origin = parse_vector(args[1]);
	shape->color = parse_color(args[ft_argsize(args) - 1]);
	return (shape);
}

void	build_sphere(char **args, void *ptr)
{
	t_shape	*spere;

	spere = build_shape(args, SHAPE_SPHERE);
	spere->sp = (t_mask_sphere){atod(args[2]) / 2};
	spere->material = (t_material){MATERIAL_MIRROR, 0.6, 2.0};
	ft_lstadd_back(ptr, ft_lstnew(spere));
}

void	build_plane(char **args, void *ptr)
{
	t_shape	*plane;

	plane = build_shape(args, SHAPE_PLANE);
	plane->pl.normal = parse_vector_norm(args[2]);
	ft_lstadd_back(ptr, ft_lstnew(plane));
}

void	build_cylinder(char **args, void *ptr)
{
	t_shape	*cylinder;

	cylinder = build_shape(args, SHAPE_CYLINDER);
	cylinder->cy.normal = parse_vector_norm(args[2]);
	cylinder->cy.radius = atod(args[3]) / 2;
	cylinder->cy.height = atod(args[4]);
	cylinder->cy.axis = vec3_cross(cylinder->cy.normal, vec3(0, 1, 0));
	vec3_normalize(&cylinder->cy.axis);
	cylinder->cy.angle = vec3_angle(cylinder->cy.normal, vec3(0, 1, 0));
	ft_lstadd_back(ptr, ft_lstnew(cylinder));
}
