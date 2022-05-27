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
#include "log.h"
#include "shape.h"
#include "../lib/libft/include/libft.h"

#define ESC 256

void	_mlx_keypress(int key, int os_key, void *program)
{
	if (key == ESC)
	{
		program_terminate(program);
		exit(EXIT_SUCCESS);
	}
	(void)os_key;
}

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
	//mlx_image_to_window(program->mlx, program->buffer, 0, 0);
	if (mlx_image_to_window(program->mlx, program->buffer, 0, 0) == NULL)
		LOG_ERR("Unable to put image to window");
	else
		LOG("Put screen buffer to window");
	LOG("Drawing scene...");
	scene_draw(program);
	//ft_bzero(program->buffer->pixels, program->buffer->width * program->buffer->height);
	LOG("Scene drawn");
	mlx_key_hook(program->mlx, _mlx_keypress, program);
	LOG("ESC hook");
	LOG("Running mlx_loop");
	mlx_loop(program->mlx);
}

void	program_terminate(t_program *program)
{
	mlx_delete_image(program->mlx, program->buffer);
	LOG("Freed screen buffer");
	mlx_terminate(program->mlx);
	LOG("Terminated MLX");
	ft_lstclear(&program->shapes, shape_free);
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
