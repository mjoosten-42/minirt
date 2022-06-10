/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:00:07 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/10 11:54:23 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "color.h"
#include "config.h"

t_color	calc_pixel(t_program *program, double x, double y);

t_color	anti_aliasing(t_program *program, double x, double y)
{
	t_color	color;
	double	i;
	double	j;

	color = color_f(0, 0, 0);
	j = 0;
	while (j < AA)
	{
		i = 0;
		while (i < AA)
		{
			color = color_add(
				color, calc_pixel(program,
					x - 0.5 + i / AA,
					y - 0.5 + j / AA));
			i++;
		}
		j++;
	}
	color.r /= (AA * AA);
	color.g /= (AA * AA);
	color.b /= (AA * AA);
	return (color);
}
