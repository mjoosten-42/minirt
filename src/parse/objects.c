/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 10:49:24 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/05 11:04:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "libft.h"
#include "program.h"
#include "light.h"
#include <math.h>

void	build_ambience(char **args, t_program *program)
{
	static int	once;
	t_ambience	ambience;

	if (once)
		rt_error(NULL, "Multiple ambient lightings");
	ambience.intensity = atod(double_err_check(args[1]));
	if (ambience.intensity < 0 || ambience.intensity > 1)
		rt_error(args[1], "intensity out of range");
	ambience.color = parse_color(args[2]);
	program->ambience = ambience;
	once = 1;
}

void	build_camera(char **args, t_program *program)
{
	static int	once;
	t_cam		camera;

	if (once)
		rt_error(NULL, "Multiple cameras");
	camera.origin = parse_vector(args[1]);
	camera.direction = parse_vector_norm(args[2]);
	camera.fov = ft_atoi(args[3]);
	if (camera.fov < 0 || camera.fov > 180)
		rt_error(args[3], "fov out of range");
	camera.fov = tan(camera.fov / 2 * M_PI / 180);
	camera_calculate_matrix(&camera);
	program->camera = camera;
	once = 1;
}

void	build_light(char **args, t_program *program)
{
	t_light	*light;

	light = ft_malloc(sizeof(t_light));
	light->o = parse_vector(args[1]);
	light->intensity = atod(double_err_check(args[2]));
	if (light->intensity < 0 || light->intensity > 1)
		rt_error(args[2], "brightness out of range");
	light->color = parse_color(args[3]);
	ft_lstadd_back(&program->lights, ft_lstnew(light));
}

void	light_print(const t_light *light)
{
	if (!ENABLE_DEBUG)
		return ;
	printf("# - LIGHT - - - - - - - - - - - - - - - -\n");
	printf("|  origin ");
	vec3_print(light->o);
	printf("|  color ");
	color_print_f(light->color);
	printf("|  intensity: %.3f\n", light->intensity);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
