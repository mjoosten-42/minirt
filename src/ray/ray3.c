/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ray3.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/15 19:32:21 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/01 17:34:04 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ray3.h"

t_ray3	ray3(t_v3 origin, t_v3 normalized_direction)
{
	return ((t_ray3){origin, normalized_direction, INFINITY, 0});
}
