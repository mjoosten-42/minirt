/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   _init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:40:33 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 15:10:58 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "utils.h"
#include "log.h"

static t_program	*_allocate(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (program != NULL)
		ft_bzero(program, sizeof(t_program));
	return (program);
}

void	_init_mlx(t_program *program)
{
	program->mlx = mlx_init(WINDOW_W, WINDOW_H, WINDOW_TITLE, WINDOW_RESIZE);
	if (program->mlx == NULL)
	{
		LOG_ERR("Failed to initialize MLX");
		exit(EXIT_FAILURE);
	}
	LOG("Initialized MLX");
	program->buffer = mlx_new_image(program->mlx, WINDOW_W, WINDOW_H);
	if (program->buffer == NULL)
	{
		LOG_ERR("Failed to initialize screen buffer");
		exit(EXIT_FAILURE);
	}
	LOG("Initialized screen buffer");
}

void	program_run(t_program *program)
{
	mlx_image_to_window(program->mlx, program->buffer, 0, 0);
	LOG("Put screen buffer to window");
	LOG("Running mlx_loop");
	mlx_loop(program->mlx);
}

void	program_terminate(t_program *program)
{
	mlx_terminate(program->mlx);
	LOG("Terminated MLX");
	//ADD WAY TO FREE SHAPES (AND THEIR MASKS)
	ft_lstclear(&program->shapes, free);
	LOG("Freed shape list");
	free(program);
	LOG("Freed program struct");
}

t_program	*program_get(void)
{
	static t_program	*program = NULL;

	if (program == NULL)
	{
		program = _allocate();
		if (program != NULL)
		{
			LOG("Allocated program struct");
			_init_mlx(program);
		}
		else
			LOG_ERR("Failed to allocate program struct");
	}
	return (program);
}
