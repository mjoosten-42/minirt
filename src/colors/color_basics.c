/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:38:34 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/05 11:15:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include <math.h>

t_color	color_rgb(int r, int g, int b)
{
	return ((t_color){(float)r / 255.0, (float)g / 255.0, (float)b / 255.0});
}

int	color_to_int(t_color c)
{
	unsigned char	trgb[4];

	trgb[1] = c.b * 255;
	trgb[2] = c.g * 255;
	trgb[3] = c.r * 255;
	trgb[0] = 255;
	return (*(int *)trgb);
}

void	color_normalize(t_color *c)
{
	float	largest;

	if (c->r >= c->g && c->r >= c->b)
		largest = c->r;
	else if (c->g >= c->r && c->g >= c->b)
		largest = c->g;
	else
		largest = c->b;
	c->r /= largest;
	c->g /= largest;
	c->b /= largest;
}
