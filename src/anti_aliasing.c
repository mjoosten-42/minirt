/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   anti_aliasing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 16:00:07 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/05 12:45:42 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "color.h"
#include "config.h"
#include <time.h>
#include <stdlib.h>
#include "libft.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

t_color	calc_pixel(const t_program *program, double x, double y);

t_color	anti_aliasing(const t_program *program, double x, double y)
{
	t_color	color;
	int		i;
	int		j;

	color = (t_color){0, 0, 0};
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
	int	i;

	i = 0;
	srand(time(NULL));
	shuffled = ft_malloc(sizeof(int) * pixels);
	while (i < pixels)
	{
		shuffled[i] = i;
		i++;
	}
	while (i-- > 1)
		swap(&shuffled[i], &shuffled[rand() % i]);
	return (shuffled);
}
