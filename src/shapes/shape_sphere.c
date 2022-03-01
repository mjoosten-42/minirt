/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape_sphere.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 12:06:19 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/01 12:23:03 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shape.h"
#include "ray3.h"

t_mask_sphere	shape_sphere_mask(double radius)
{
	return ((t_mask_sphere){radius});
}

static double	_discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

int	shape_sphere_collision(const t_shape *sphere, const t_ray3 *ray)
{
	t_v3 	len_vec;
	double	discr;
	double	radius;

	radius = ((t_mask_sphere *)sphere->mask)->radius;
	len_vec = vec3_sub(ray->origin, sphere->origin);
	discr = _discriminant(vec3_dot(ray->direction, ray->direction),
		vec3_dot(ray->direction, len_vec) * 2.0,
		vec3_dot(len_vec, len_vec) - radius);
	if (discr < 0)
		return (0);
	return (1);
}

//int	solve_quadratic(double a, double b, double c, double *t0)
//{
//	double	discr;
//	double	q;
//	double	t1;

//	*t0 = -0.5 * b / a;
//	t1 = *t0;
//	discr = b * b - 4 * a * c;
//	if (discr < 0)
//		return (0);
//	else if (discr != 0)
//	{
//		if (b > 0)
//			q = -1 * (b + sqrt(discr)) / 2;
//		else
//			q = -1 * (b - sqrt(discr)) / 2;
//		*t0 = q / a;
//		t1 = c / q;
//	}
//	if (*t0 > t1)
//		swap_doubles(t0, &t1);
//	if (*t0 < 0)
//		*t0 = t1;
//	return (1);
//}

//int	intersect_sphere(t_ray *ray, t_shape *sphere)
//{
//	double	t;
//	t_v3	l;
//	double	a;
//	double	b;
//	double	c;

//	l = vec3_sub(ray->o, sphere->o);
//	a = vec3_dot(ray->d, ray->d);
//	b = 2.0 * vec3_dot(ray->d, l);
//	c = vec3_dot(l, l) - (sphere->r * sphere->r);
//	if (solve_quadratic(a, b, c, &t) == 0)
//		return (0);
//	if (t < 0)
//		return (0);
//	ray->t = t;
//	ray_set_p(ray);
//	return (1);
//}
