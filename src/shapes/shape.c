/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:55:37 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/20 14:45:11 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "parse.h"
#include "vec3.h"
#include "libft.h"
#include "collision.h"
#include "config.h"
#include "objects.h"

static t_material	parse_material(char *str)
{
	const static t_material	table[] = {
	{"water", 0.2, 0.5, 1.3, DEFAULT_PHONG},
	{"mirror", 0.9, 0.0, 1.0, INFINITY},
	{"glass", 0.0, 0.9, 1.5, INFINITY},
	{"metal", 0.5, 0.1, 2.0, 2.0}
	};
	int						tablesize;
	int						len;
	int						i;

	if (!str)
		return ((t_material){NULL, 0, 0, 1, INFINITY});
	i = 0;
	len = ft_strlen(str);
	tablesize = sizeof(table) / sizeof(*table);
	while (i < tablesize)
	{
		if (ft_strncmp(str, table[i].name, len) == 0)
			return (table[i]);
		i++;
	}
	return ((t_material){NULL, 0, 0, 1, DEFAULT_PHONG});
}

static t_shape	*build_shape(char **args, t_object_type type, void *ptr)
{
	t_shape	*shape;

	shape = ft_malloc(sizeof(t_shape));
	shape->type = type;
	shape->o = parse_vector(args[1]);
	shape->material = parse_material(args[ft_argsize(args) - 1]);
	ft_lstadd_front(ptr, ft_lstnew(shape));
	return (shape);
}

void	build_sphere(char **args, void *ptr)
{
	t_shape	*sphere;

	sphere = build_shape(args, OBJECT_SPHERE, ptr);
	sphere->sp = (t_mask_sphere){atod(args[2]) / 2};
	sphere->color = parse_color(args[3]);
	sphere->f = collision_sphere;
}

void	build_plane(char **args, void *ptr)
{
	t_shape	*plane;

	plane = build_shape(args, OBJECT_PLANE, ptr);
	plane->n = parse_vector_norm(args[2]);
	plane->color = parse_color(args[3]);
	plane->f = collision_plane;
}

void	build_cylinder(char **args, void *ptr)
{
	t_shape	*cylinder;

	cylinder = build_shape(args, OBJECT_CYLINDER, ptr);
	cylinder->n = parse_vector_norm(args[2]);
	cylinder->cy.radius = atod(args[3]) / 2;
	cylinder->cy.height = atod(args[4]);
	cylinder->color = parse_color(args[5]);
	cylinder->cy.axis = vec3_norm(vec3_cross(cylinder->n, vec3(0, 1, 0)));
	cylinder->cy.angle = vec3_angle(cylinder->n, vec3(0, 1, 0));
	cylinder->f = collision_cylinder;
}

void	build_cone(char **args, void *ptr)
{
	t_shape	*cone;

	cone = build_shape(args, OBJECT_CONE, ptr);
	cone->n = parse_vector_norm(args[2]);
	cone->co.radius = atod(args[3]) / 2;
	cone->co.height = atod(args[4]);
	cone->color = parse_color(args[5]);
	cone->co.angle = atan(cone->co.radius / cone->co.height);
	cone->co.angle = cos(cone->co.angle) * cos(cone->co.angle);
	cone->f = collision_cone;
}
