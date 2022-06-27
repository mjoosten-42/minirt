/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:59:35 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/27 16:46:35 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equations.h"
#include <math.h>

static void	swap(double t[2])
{
	double	tmp;

	tmp = t[0];
	t[0] = t[1];
	t[1] = tmp;
}

int	quadratic(double t[2], t_abc values)
{
	double	d;

	d = values.b * values.b - 4.0 * values.a * values.c;
	if (d < 0)
		return (-1);
	d = sqrt(d);
	t[0] = (-values.b - d) / (2 * values.a);
	t[1] = (-values.b + d) / (2 * values.a);
	if (t[0] > t[1])
		swap(t);
	if (t[0] < 0)
		swap(t);
	return (0);
}
