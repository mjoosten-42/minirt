/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:42:17 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/09 16:01:30 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "collision.h"
#include "color.h"
#include "raycasting.h"
#include <math.h>

t_color	ray_to_light(t_program *program, t_collision coll);

static t_v3	_get_origin(t_program *program)
{
	return (program->camera.origin);
}

static t_v3	_get_direction(t_program *program, double x, double y)
{
	t_v3	direction;
	double	aspect;

	aspect = ((double)program->mlx->width / (double)program->mlx->height);
	direction.x = (2.0 * (x + 0.5) / program->mlx->width - 1.0)
		* program->camera.fov * aspect;
	direction.y = (1.0 - 2.0 * (y + 0.5) / program->mlx->height)
		* program->camera.fov;
	direction.z = 1.0;
	vec3_normalize(&direction);
	direction = mat4_mul_vec3(&program->camera.view_matrix, &direction);
	vec3_normalize(&direction);
	return (direction);
}

//	This function gets run for every pixel, returning the color
t_color	calc_pixel(t_program *program, double x, double y)
{
	t_ray3			ray;
	t_rdata			rdata;

	ray = ray3(_get_origin(program), _get_direction(program, x, y));
	rdata = raycast(program, &ray);
	if (rdata.last_coll.shape != NULL)
		return (rdata.color);
	return (color_f(0, 0, 0));
}

void	scene_draw(void *ptr)
{
	t_program				*program;
	unsigned int			x;
	unsigned int			y;
	t_color					c;
	static unsigned int		i;
	static int				*shuffled;

	program = (t_program *)ptr;
	pthread_mutex_lock(&program->threads.mutex);
	if (!shuffled)
		shuffled = shuffle(program->buffer->width * program->buffer->height);
	while (i < program->buffer->width * program->buffer->height)
	{
		x = shuffled[i] % program->buffer->width;
		y = shuffled[i] / program->buffer->width;
		i++;
		pthread_mutex_unlock(&program->threads.mutex);
		c = anti_aliasing(program, x, y);
		color_cap(&c);
		mlx_putpixel(program->buffer, x, y, color_to_int(c));
		pthread_mutex_lock(&program->threads.mutex);
	}
	if (shuffled)
	{
		free(shuffled);
		shuffled = NULL;
	}
	pthread_mutex_unlock(&program->threads.mutex);
}
