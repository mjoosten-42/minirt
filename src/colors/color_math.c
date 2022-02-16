/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_math.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:02:48 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/16 15:33:42 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_blend(t_color c1, t_color c2, float percentage)
{
	t_color	result;

	result.r = c1.r + (c2.r - c1.r) * percentage;
	result.g = c1.g + (c2.g - c1.g) * percentage;
	result.b = c1.b + (c2.b - c1.b) * percentage;
	return (result);
}

void	color_luminosity(t_color *c, float multiplier)
{
	c->r *= multiplier;
	c->g *= multiplier;
	c->b *= multiplier;
}

/*
**	Only normalizes the color if one of the elements is above 1.0
*/
void	color_norm_if_large(t_color *c)
{
	if (c->r > 1.0 || c->g > 1.0 || c->b > 1.0)
		color_normalize(c);
}

void	color_cap(t_color *c)
{
	if (c->r > 1.0)
		c->r = 1.0;
	if (c->g > 1.0)
		c->g = 1.0;
	if (c->b > 1.0)
		c->b = 1.0;
}
