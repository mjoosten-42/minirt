/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equations.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:01:02 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 13:32:46 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUATIONS_H
# define EQUATIONS_H

# include "vec3.h"

typedef struct s_abc
{
	double	a;
	double	b;
	double	c;
}	t_abc;

void	_quadratic(double t[2], t_abc values, double discr);
double	_discriminant(t_abc values);

t_v3	rodrigues(t_v3 v, t_v3 axis, double angle);

#endif