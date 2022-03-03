/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   collisions.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 12:06:19 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 15:54:40 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "collision.h"
#include <math.h>

typedef struct s_abc
{
	double	a;
	double	b;
	double	c;
}	t_abc;

void	*collision_get_func(t_shape_type type)
{
	static const t_collfunc	f[] =
	{
		[SHAPE_NONE] = NULL,
		[SHAPE_PLANE] = NULL,
		[SHAPE_SQUARE] = NULL,
		[SHAPE_CIRCLE] = NULL,
		[SHAPE_TRIANGLE] = NULL,
		[SHAPE_SPHERE] = collision_sphere
	};

	return (f[type]);
}

static double	_discriminant(t_abc values)
{
	return (values.b * values.b - 4.0 * values.a * values.c);
}

static void	_quadratic(double t[2], t_abc values, double discr)
{
	double	q;
	double	temp;

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
}

t_collision	collision_sphere(const t_shape *sphere, const t_ray3 *ray)
{
	t_v3 			len_vec;
	t_abc			values;
	double			discr;
	double			t[2];
	t_collision		coll;

	coll = collision_none();
	len_vec = vec3_sub(ray->origin, sphere->origin);
	values.a = vec3_dot(ray->direction, ray->direction);
	values.b = 2.0 * vec3_dot(ray->direction, len_vec);
	values.c = vec3_dot(len_vec, len_vec) - pow(((t_mask_sphere *)sphere->mask)->radius, 2);
	discr = _discriminant(values);
	if (discr < 0)
		return (coll);
	_quadratic(t, values, discr);
	coll.shape = (t_shape *)sphere;
	coll.point = vec3_add(ray->origin, vec3_mul(ray->direction, t[0]));
	coll.normal = vec3_sub(coll.point, sphere->origin);
	vec3_normalize(&(coll.normal));
	return (coll);
}
