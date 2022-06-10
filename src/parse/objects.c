/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:49:24 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/10 15:13:26 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "program.h"
#include "light.h"
#include "log.h"
#include <math.h>

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
	light->o = parse_vector(args[1]);
	light->intensity = atod(args[2]);
	if (light->intensity < 0 || light->intensity > 1)
	{
		LOG_ERR("Brightness out of range");
		exit(EXIT_FAILURE);
	}
	light->color = parse_color(args[3]);
	ft_lstadd_back(ptr, ft_lstnew(light));
}

void	light_print(t_light *light)
{
	printf("# - LIGHT - - - - - - - - - - - - - - - -\n");
	printf("|  origin ");
	vec3_print(light->o);
	printf("|  color ");
	color_print_f(light->color);
	printf("|  intensity: %.3f\n", light->intensity);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
