/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:59:35 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 14:44:40 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "equations.h"
#include <math.h>

int	_quadratic(double t[2], t_abc values)
{
	double	discr;
	double	q;
	double	temp;

	discr = values.b * values.b - 4.0 * values.a * values.c;
	if (discr < 0)
		return (-1);
	t[0] = -0.5 * values.b / values.a;
	t[1] = t[0];
	if (values.b > 0)
		q = -1 * (values.b + sqrt(discr)) / 2;
	else
		q = -1 * (values.b - sqrt(discr)) / 2;
	t[0] = q / values.a;
	t[1] = values.c / q;
	if (t[0] > t[1])
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
	if (t[0] < 0)
		t[0] = t[1];
	return (0);
}
