/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vec3_debug.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:26:48 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/15 19:29:41 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include <stdio.h>

void	vec3_print(t_v3 vec3)
{
	printf(VECTOR_DEBUG_PRINT_MESSAGE, vec3.x, vec3.y, vec3.z);
}