/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:34:01 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/10 15:12:20 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"
#include <stdio.h>

void	ray_print(t_ray3 ray3)
{
	printf("# -  RAY  - - - - - - - - - - - - - - - -\n");
	printf("| origin ");
	vec3_print(ray3.o);
	printf("| direction ");
	vec3_print(ray3.d);
	printf("| distance: ");
	if (ray3.distance == INFINITY)
		printf("INFINITY\n");
	else if (ray3.distance > 10000)
		printf("%.2e\n", ray3.distance);
	else
		printf("%.2f\n", ray3.distance);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
