/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray3_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:34:01 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/15 19:56:13 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include <stdio.h>

void	ray_print(t_ray3 ray3)
{
	printf("ray:\n");
	printf("  origin ");
	vec3_print(ray3.origin);
	printf("  direction ");
	vec3_print(ray3.direction);
	printf("  distance: ");
	if (ray3.distance == INFINITY)
		printf("INFINITY\n");
	else if (ray3.distance > 10000)
		printf("%.2e\n", ray3.distance);
	else
		printf("%.2f\n", ray3.distance);
}
