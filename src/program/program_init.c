/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:40:33 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/17 18:04:45 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "utils.h"

static t_program	*program_allocate(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (program != NULL)
		ft_bzero(program, sizeof(t_program));
	return (program);
}

void	program_init(t_program *program)
{
	program->mlx = mlx_init();
	if (program->mlx == NULL)
		exit(1);
	program->window = mlx_new_window(program->mlx, program->size_x, program->size_y, WINDOW_TITLE);
	if (program->window == NULL)
		exit(1);
	program->buffer = img_create();
}

void	program_free(t_program *program)
{
	mlx_destroy_window(program->mlx, program->window);
	mlx_destroy_image(program->mlx, program->buffer->mlx_img);
	free(program);
}

t_program	*program_get(void)
{
	static t_program	*program = NULL;

	if (program == NULL)
	{
		program = program_allocate();
		if (program != NULL)
			program_init(program);
	}
	return (program);
}
