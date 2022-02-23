/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 20:08:57 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/23 10:50:32 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT

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

t_light	*light_create(t_v3 origin, t_color color);

#endif
