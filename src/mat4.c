/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:23:57 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/09 11:19:43 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat4.h"

static void	_matrix_set_column(double column[4], t_v3 set)
{
	column[0] = set.x;
	column[1] = set.y;
	column[2] = set.z;
	column[3] = 0;
}

t_mat4	matrix(t_v3 right, t_v3 up, t_v3 forward, t_v3 origin)
{
	t_mat4	m;

	_matrix_set_column(m.data[0], right);
	_matrix_set_column(m.data[1], up);
	_matrix_set_column(m.data[2], forward);
	_matrix_set_column(m.data[3], origin);
	m.data[3][3] = 1;
	return (m);
}

t_v3	mat4_mul_vec3(const t_mat4 *m, const t_v3 *vec)
{
	t_v3	r;
	double	t[4];

	t[0] = vec->x * m->data[0][0] + vec->y * m->data[1][0]
		+ vec->z * m->data[2][0] + m->data[3][0];
	t[1] = vec->x * m->data[0][1] + vec->y * m->data[1][1]
		+ vec->z * m->data[2][1] + m->data[3][1];
	t[2] = vec->x * m->data[0][2] + vec->y * m->data[1][2]
		+ vec->z * m->data[2][2] + m->data[3][2];
	t[3] = vec->x * m->data[0][3] + vec->y * m->data[1][3]
		+ vec->z * m->data[2][3] + m->data[3][3];
	r.x = t[0] / t[3];
	r.y = t[1] / t[3];
	r.z = t[2] / t[3];
	return (r);
}
