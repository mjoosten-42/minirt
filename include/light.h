/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:08:57 by ngerrets          #+#    #+#             */
/*   Updated: 2022/05/31 11:46:36 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vec3.h"
# include "color.h"

# define LIGHT_DEFAULT_INTENSITY 1.0
# define LIGHT_DEFAULT_RANGE 128.0

/**
**	Struct that represents a light-source (point-light).
**	TODO: Need a value/way to calculate light fall-off over distance.
**	@param origin <t_v3> Point of origin vector
**	@param color <t_color> Color of the light
**	@param intensity <float> Color gets multiplied by this value.
**	@param range <double> Maximum range the light reaches.
*/
typedef struct s_light
{
	t_v3	origin;
	t_color	color;
	float	intensity;
	double	range;
}			t_light;

/**
**	Ambient lighting data
**	@param intensity <float> Intensity
**	@param color <t_color> Light color.
*/
typedef struct s_ambience
{
	float	intensity;
	t_color	color;
}			t_ambience;

t_light	*light_create(t_v3 origin, t_color color);
void	light_print(t_light *light);

#endif
