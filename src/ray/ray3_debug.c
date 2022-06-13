/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray3_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:34:01 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/13 14:51:43 by mjoosten         ###   ########.fr       */
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
	printf("| bounces: %d\n", ray3.bounces);
	printf("# - - - - - - - - - - - - - - - - - - - -\n");
}
