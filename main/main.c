/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 11:11:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 11:39:39 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "log.h"
#include "shape.h"

static void	_add_shape(t_list **list, t_shape *shape)
{
	ft_lstadd_back(list, ft_lstnew(shape));
}

static void	_build_shapes(t_program *program)
{
	t_shape	*shape;
	void	*mask;

	mask = shape_mask(SHAPE_SQUARE, &(t_mask_square){vec3(0, 1, 0), 10});
	shape = shape_create(SHAPE_SQUARE, vec3(0, 1, 1), color_f(0.5, 0.5, 0), mask);
	_add_shape(&program->shapes, shape);

	mask = shape_mask(SHAPE_CIRCLE, &(t_mask_circle){vec3(0, 0, 1), 5});
	shape = shape_create(SHAPE_CIRCLE, vec3(0, 5, 0), color_f(0.1, 0.9, 0), mask);
	_add_shape(&program->shapes, shape);

	mask = shape_mask(SHAPE_PLANE, &(t_mask_plane){vec3(0, -1, 0)});
	shape = shape_create(SHAPE_PLANE, vec3(9, 0, 1), color_f(0, 0.7, 0), mask);
	_add_shape(&program->shapes, shape);

	mask = shape_mask(SHAPE_SPHERE, &(t_mask_sphere){3});
	shape = shape_create(SHAPE_SPHERE, vec3(0, 0, 5), color_f(0, 1.0, 0), mask);
	_add_shape(&program->shapes, shape);

	ft_lstiter(program->shapes, (void (*)(void *))shape_print);
}

#include "utils.h"

void	ft_bfull(void *s, size_t length)
{
	unsigned char	*d;
	size_t			i;

	d = s;
	i = 0;
	while (i < length)
	{
		d[i] = 255;
		i++;
	}
}

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

int	main(void)
{
	t_program	*program;

	program = program_get();
	if (program == NULL)
		return (EXIT_FAILURE);
	program->buffer = mlx_new_image(program->mlx, WINDOW_W, WINDOW_H);
	if (program->buffer == NULL)
	{
		LOG_ERR("Failed to initialize screen buffer");
		exit(EXIT_FAILURE);
	}
	LOG("Initialized screen buffer");

	mlx_image_to_window(program->mlx, program->buffer, 0, 0);
	_clear(program->buffer);

	_build_shapes(program);
	program_run(program);
	program_terminate(program);
	LOG("Program end");
	return (EXIT_SUCCESS);
}
