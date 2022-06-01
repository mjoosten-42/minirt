/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scene_draw.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/01 11:42:17 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/06/01 17:05:12 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "collision.h"
#include "color.h"
#include <math.h>

t_color	ray_to_light(t_program *program, t_collision coll);

static t_v3	_get_origin(t_program *program)
{
	return (program->camera.origin);
}

static t_v3 _get_direction(int x, int y, t_program *program)
{
	t_v3	direction;
	double	aspect;

	aspect = ((double)program->mlx->width / (double)program->mlx->height);
	direction.x = (2.0 * (x + 0.5) / program->mlx->width - 1.0) *
		program->camera.fov * aspect;
	direction.y = (1.0 - 2.0 * (y + 0.5) / program->mlx->height) *
		program->camera.fov;
	direction.z = 1.0;
	vec3_normalize(&direction);
	direction = mat4_mul_vec3(&program->camera.view_matrix, &direction);
	vec3_normalize(&direction);
	return (direction);
}

//static t_v3	_apply_rotation(t_v3 *dir, t_cam* camera)
//{
	
//}

static void	_clear(t_mlx_image *img)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_putpixel(img, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
}

//	This function gets run for every pixel, returning the color that it should have
t_color	calc_pixel(t_program *program, unsigned int x, unsigned int y)
{
	t_collision		coll;
	t_ray3			ray;
	t_rdata			rdata;

	ray = ray3(_get_origin(program), _get_direction(x, y, program));
	rdata = raycast(program, &ray);
	if (rdata.last_coll.shape != NULL)
		return (rdata.color);
	return (color_f(0, 0, 0));
}

void	scene_draw(t_program *program)
{
	unsigned int	x;
	unsigned int	y;
	t_color			c;

	_clear(program->buffer);
	y = 0;
	while (y < program->buffer->height)
	{
		x = 0;
		while (x < program->buffer->width)
		{
			c = calc_pixel(program, x, y);
			color_cap(&c);
			mlx_putpixel(program->buffer, x, y, color_to_int(c));
			x++;
		}
		y++;
	}
}
