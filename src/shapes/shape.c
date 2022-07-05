/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:55:37 by mjoosten          #+#    #+#             */
/*   Updated: 2022/07/05 15:52:10 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "parse.h"
#include "vec3.h"
#include "libft.h"
#include "collision.h"
#include "objects.h"
#include "material.h"
#include "program.h"
#include <math.h>

static t_shape	*shape(char **args, t_object_type type, t_program *program)
{
	t_shape	*shape;

	shape = ft_malloc(sizeof(t_shape));
	shape->type = type;
	shape->o = parse_vector(args[1]);
	shape->material = parse_material(args[ft_argsize(args) - 1]);
	ft_lstadd_front(&program->shapes, ft_lstnew(shape));
	return (shape);
}

void	build_sphere(char **args, t_program *program)
{
	t_shape	*sphere;

	sphere = shape(args, OBJECT_SPHERE, program);
	sphere->sp = (t_mask_sphere){atod(double_err_check(args[2])) / 2};
	sphere->color = parse_color(args[3]);
	sphere->f = collision_sphere;
}

void	build_plane(char **args, t_program *program)
{
	t_shape	*plane;

	plane = shape(args, OBJECT_PLANE, program);
	plane->pl.n = parse_vector_norm(args[2]);
	plane->color = parse_color(args[3]);
	plane->f = collision_plane;
}

void	build_cylinder(char **args, t_program *program)
{
	t_shape	*cylinder;

	cylinder = shape(args, OBJECT_CYLINDER, program);
	cylinder->cy.n = parse_vector_norm(args[2]);
	cylinder->cy.radius = atod(double_err_check(args[3])) / 2;
	cylinder->cy.height = atod(double_err_check(args[4]));
	cylinder->color = parse_color(args[5]);
	cylinder->cy.axis = vec3_norm(vec3_cross(cylinder->cy.n, vec3(0, 1, 0)));
	cylinder->cy.angle = vec3_angle(cylinder->cy.n, vec3(0, 1, 0));
	cylinder->f = collision_cylinder;
}

void	build_cone(char **args, t_program *program)
{
	t_shape	*cone;

	cone = shape(args, OBJECT_CONE, program);
	cone->cy.n = parse_vector_norm(args[2]);
	cone->co.radius = atod(double_err_check(args[3])) / 2;
	cone->co.height = atod(double_err_check(args[4]));
	cone->color = parse_color(args[5]);
	cone->co.angle = atan(cone->co.radius / cone->co.height);
	cone->co.angle = cos(cone->co.angle) * cos(cone->co.angle);
	cone->f = collision_cone;
}
