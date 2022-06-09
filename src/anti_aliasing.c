/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:00:07 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/09 16:02:06 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "color.h"

#define AA 2

static t_color	color_sum(t_color colors[AA][AA]);
t_color			calc_pixel(t_program *program, double x, double y);

t_color	anti_aliasing(t_program *program, double x, double y)
{
	t_color	colors[AA][AA];

	colors[0][0] = calc_pixel(program, x - 0.5, y - 0.5);
	colors[0][1] = calc_pixel(program, x + 0.5, y - 0.5);
	colors[1][0] = calc_pixel(program, x - 0.5, y + 0.5);
	colors[1][1] = calc_pixel(program, x + 0.5, y + 0.5);
	return (color_sum(colors));
}

static t_color	color_sum(t_color colors[AA][AA])
{
	t_color	color;
	int		i;
	int		j;

	color = color_f(0, 0, 0);
	j = 0;
	while (j < AA)
	{
		i = 0;
		while (i < AA)
		{
			color = color_add(color, colors[i][j]);
			i++;
		}
		j++;
	}
	color.r /= AA * AA;
	color.g /= AA * AA;
	color.b /= AA * AA;
	return (color);
}
