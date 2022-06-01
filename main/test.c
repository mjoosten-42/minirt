/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:38:16 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/01 13:26:55 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include "color.h"
#include "shape.h"
#include "mat4.h"

int	main(void)
{
	t_v3	origin;
	t_v3	direction;
	t_ray3	ray;
	t_color	c1;
	t_color	c2;

	origin = vec3(0, 0, 0);
	direction = vec3(10, 1, 0);
	vec3_print(direction);
	vec3_normalize(&direction);
	ray = ray3(origin, direction);
	ray.distance = 15.7389;
	ray_print(ray);

	c1 = color_f(0.9, 2.0, 0.1);
	color_normalize(&c1);
	//c1 = color_from_int(color_to_int(c1));
	c2 = color_f(0, 0, 0.05);
	color_print_f(c1);
	t_color blend;
	blend = color_blend(c1, c2, 0.5);
	color_print_f(blend);
	color_print_hex(blend);
	printf("\n\n");

	t_shape	*shape;
	shape = shape_create(SHAPE_SQUARE, vec3(1, 1, 1), color_f(1, 0, 0),
		shape_mask(SHAPE_SQUARE, &(t_mask_square){vec3(0, 1, 0), 10.0}));
	shape_print(shape);

	t_mat4 m;

	m = matrix(vec3(1, 1, 1), vec3(2, 2, 2), vec3(3, 3, 3), vec3(4, 4, 4));

	printf("%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",
		m.data[0][0], m.data[0][1], m.data[0][2], m.data[0][3],
		m.data[1][0], m.data[1][1], m.data[1][2], m.data[1][3],
		m.data[2][0], m.data[2][1], m.data[2][2], m.data[2][3],
		m.data[3][0], m.data[3][1], m.data[3][2], m.data[3][3]);

	return (0);
}