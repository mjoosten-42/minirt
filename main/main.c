/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 11:11:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 19:29:50 by ngerrets      ########   odam.nl         */
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
	ft_lstiter(program->shapes, (void (*)(void *))shape_print);
}

int	main(void)
{
	t_program	*program;

	program = program_get();
	if (program == NULL)
		return (EXIT_FAILURE);
	_build_shapes(program);
	program_run(program);
	program_terminate(program);
	LOG("Program end");
	return (EXIT_SUCCESS);
}
