/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:02:48 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 14:00:50 by mjoosten         ###   ########.fr       */
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

t_color	color_luminosity(t_color c, float mul)
{
	if (mul < 0)
		mul = 0;
	return ((t_color){c.r * mul, c.g * mul, c.b * mul});
}

t_color	color_mul(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r * c2.r;
	result.g = c1.g * c2.g;
	result.b = c1.b * c2.b;
	return (result);
}

void	color_cap(t_color *c)
{
	if (c->r > 1.000)
		c->r = 1.000;
	if (c->g > 1.000)
		c->g = 1.000;
	if (c->b > 1.000)
		c->b = 1.000;
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	result;

	result.r = c1.r + c2.r;
	result.g = c1.g + c2.g;
	result.b = c1.b + c2.b;
	return (result);
}
