/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   light.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 20:08:57 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 20:15:18 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT

# include "vec3.h"
# include "color.h"

# define LIGHT_DEFAULT_INTENSITY 1.0
# define LIGHT_DEFAULT_RANGE 128.0

typedef struct s_light
{
	t_v3	origin;
	t_color	color;
	float	intensity;
	double	range;
}			t_light;

#endif
