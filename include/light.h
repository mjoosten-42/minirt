/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:08:57 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/10 15:13:12 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vec3.h"
# include "color.h"

/**
**	Struct that represents a light-source (point-light).
**	TODO: Need a value/way to calculate light fall-off over distance.
**	@param o <t_v3> Point of origin vector
**	@param color <t_color> Color of the light
**	@param intensity <float> Color gets multiplied by this value.
*/
typedef struct s_light
{
	t_v3	o;
	t_color	color;
	float	intensity;
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
