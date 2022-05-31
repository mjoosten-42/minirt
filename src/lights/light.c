/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:08:42 by ngerrets          #+#    #+#             */
/*   Updated: 2022/05/31 11:47:41 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "log.h"
#include <stdlib.h>
#include <stdio.h>

t_light	*light_create(t_v3 origin, t_color color)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (light == NULL)
	{
		LOG_ERR("Failed to allocate light");
		return (NULL);
	}
	LOG("Light allocated");
	light->origin = origin;
	light->color = color;
	light->intensity = LIGHT_DEFAULT_INTENSITY;
	light->range = LIGHT_DEFAULT_RANGE;
	return (light);
}

void	light_print(t_light *light)
{
	printf("# - LIGHT - - - - - - - - - - - - - - - -\n");
	printf("|  origin ");
	vec3_print(light->origin);
	printf("|  color ");
	color_print_f(light->color);
	printf("|  intensity: %.3f\n", light->intensity);
	printf("|  range: %.3f\n", light->range);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
