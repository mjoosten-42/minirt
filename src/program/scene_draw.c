/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:42:17 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/27 16:06:08 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "collision.h"
#include "color.h"
#include "raycasting.h"
#include <math.h>

static t_v3	_get_direction(const t_program *program, double x, double y)
{
	t_v3	direction;
	double	aspect;

	aspect = ((double)WINDOW_W / (double)WINDOW_H);
	direction.x = (2.0 * (x + 0.5) / WINDOW_W - 1.0)
		* program->camera.fov * aspect;
	direction.y = (1.0 - 2.0 * (y + 0.5) / WINDOW_H)
		* program->camera.fov;
	direction.z = 1.0;
	direction = vec3_norm(mat4_mul_vec3(&program->camera.view_matrix, &direction));
	return (direction);
}

//	This function gets run for every pixel, returning the color
t_color	calc_pixel(const t_program *program, double x, double y)
{
	t_rdata	rdata;
	t_ray3	ray;

	ray = ray3(program->camera.origin, _get_direction(program, x, y));
	rdata = raycast(program, &ray);
	if (rdata.last_coll.shape != NULL)
		return (rdata.color);
	return (color_f(0, 0, 0));
}

void	scene_draw(void *ptr)
{
	t_program			*program;
	t_color				color;
	unsigned int		x;
	unsigned int		y;
	static unsigned int	i;

	program = (t_program *)ptr;
	pthread_mutex_lock(&program->threads.mutex);
	while (i < WINDOW_W * WINDOW_H)
	{
		x = program->shuffled[i] % WINDOW_W;
		y = program->shuffled[i] / WINDOW_W;
		i++;
		pthread_mutex_unlock(&program->threads.mutex);
		color = anti_aliasing(program, x, y);
		color_cap(&color);
		mlx_put_pixel(program->buffer, x, y, color_to_int(color));
		pthread_mutex_lock(&program->threads.mutex);
	}
	pthread_mutex_unlock(&program->threads.mutex);
}
