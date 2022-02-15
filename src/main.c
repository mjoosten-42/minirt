/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:38:16 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/15 19:56:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"

int	main(void)
{
	t_v3	origin;
	t_v3	direction;
	t_ray3	ray;

	origin = vec3(0, 0, 0);
	direction = vec3(10, 8, 3);
	vec3_normalize(&direction);
	ray = ray3(origin, direction);
	ray.distance = 15.7389;
	ray_print(ray);
	return (0);
}