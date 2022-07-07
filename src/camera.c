/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:51:12 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 11:24:15 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "vec3.h"

void	camera_calculate_matrix(t_cam *camera)
{
	t_v3	up;
	t_v3	right;

	right = vec3_cross((t_v3){0, 1, 0}, camera->direction);
	if (vec3_length(right) == 0)
		right = (t_v3){1, 0, 0};
	else
		right = vec3_norm(right);
	up = vec3_norm(vec3_cross(camera->direction, right));
	camera->view_matrix = matrix(right, up, camera->direction, (t_v3){0, 0, 0});
}
