/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:42:17 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/08 11:15:38 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "collision.h"
#include "color.h"
#include "raycasting.h"
#include <math.h>

void	clear_screen(mlx_image_t *img)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_W)
	{
		y = 0;
		while (y < WINDOW_H)
		{
			mlx_put_pixel(img, x, y, 0x0);
			y++;
		}
		x++;
	}
}

static t_v3	get_direction(const t_program *program, double x, double y)
{
	t_v3	direction;
	double	aspect;

	aspect = (double)WINDOW_W / (double)WINDOW_H;
	direction.x = (2.0 * (x + 0.5) / WINDOW_W - 1.0)
		* program->camera.fov * aspect;
	direction.y = (1.0 - 2.0 * (y + 0.5) / WINDOW_H)
		* program->camera.fov;
	direction.z = 1.0;
	direction = vec3_norm(
			mat4_mul_vec3(&program->camera.view_matrix, &direction));
	return (direction);
}

//	This function gets run for every pixel, returning the color
t_color	calc_pixel(const t_program *program, double x, double y)
{
	t_rdata	rdata;
	t_ray3	ray;

	ray = (t_ray3){program->camera.origin, get_direction(program, x, y), 0, 1};
	rdata = raycast(program, &ray);
	if (rdata.coll.shape == NULL)
		return ((t_color){0, 0, 0});
	return (rdata.color);
}

void	scene_draw(t_program *program)
{
	t_color				color;
	unsigned int		x;
	unsigned int		y;
	static unsigned int	i;

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
