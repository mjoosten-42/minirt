/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:49:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 11:51:34 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_masks.h"
#include "parse.h"
#include "libft.h"
#include "program.h"
#include "light.h"
#include "log.h"
#include <math.h>

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

void	build_ambience(char **args, void *ptr)
{
	static int	once;
	t_ambience	ambience;

	if (once)
	{
		LOG_ERR("Multipe ambient lightings");
		exit(EXIT_FAILURE);
	}
	ambience.intensity = atod(args[1]);
	if (ambience.intensity < 0 || ambience.intensity > 1)
	{
		LOG_ERR("Ambient lighting ratio out of range");
		exit(EXIT_FAILURE);
	}
	ambience.color = parse_color(args[2]);
	*(t_ambience *)ptr = ambience;
	once = 1;
}

void	build_camera(char **args, void *ptr)
{
	static int	once;
	t_cam		camera;

	if (once)
	{
		LOG_ERR("Multipe cameras");
		exit(EXIT_FAILURE);
	}
	camera.origin = parse_vector(args[1]);
	camera.direction = parse_vector_norm(args[2]);
	camera.fov = ft_atoi(args[3]);
	if (camera.fov < 0 || camera.fov > 180)
	{
		LOG_ERR("FOV out of range");
		exit(EXIT_FAILURE);
	}
	camera.fov = tan(camera.fov / 2 * M_PI / 180);
	camera_calculate_matrix(&camera);
	*(t_cam *)ptr = camera;
	once = 1;
}

void	build_light(char **args, void *ptr)
{
	t_light	*light;

	light = ft_malloc(sizeof(t_light));
	light->origin = parse_vector(args[1]);
	light->intensity = atod(args[2]);
	if (light->intensity < 0 || light->intensity > 1)
	{
		LOG_ERR("Brightness out of range");
		exit(EXIT_FAILURE);
	}
	light->color = parse_color(args[3]);
	ft_lstadd_back(ptr, ft_lstnew(light));
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
