/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 20:08:42 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 20:16:14 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "light.h"
#include "log.h"
#include <stdlib.h>

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
