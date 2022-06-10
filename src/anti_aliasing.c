/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_aliasing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:00:07 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/10 15:22:46 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "color.h"
#include "config.h"
#include <time.h>
#include <stdlib.h>
#include "libft.h"

t_color	calc_pixel(t_program *program, double x, double y);

t_color	anti_aliasing(t_program *program, double x, double y)
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
			color = color_add(
				color, calc_pixel(program,
					x - 0.5 + (double)i / AA,
					y - 0.5 + (double)j / AA));
			i++;
		}
		j++;
	}
	color.r /= (AA * AA);
	color.g /= (AA * AA);
	color.b /= (AA * AA);
	return (color);
}

int	*shuffle(int pixels)
{
	int	*shuffled;
	int	tmp;
	int	i;
	int	j;

	i = 0;
	srand(time(NULL));
	shuffled = ft_malloc(sizeof(int) * pixels);
	while (i < pixels)
	{
		shuffled[i] = i;
		i++;
	}
	while (i-- > 1)
	{
		j = rand() % i;
		tmp = shuffled[j];
		shuffled[j] = shuffled[i];
		shuffled[i] = tmp;
	}
	return (shuffled);
}
