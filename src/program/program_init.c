/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:43:29 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/10 11:10:00 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "log.h"
#include "shape.h"
#include "libft.h"

#define ESC 256

void	_mlx_keypress(int key, int os_key, void *program)
{
	if (key == ESC)
	{
		exit(EXIT_SUCCESS);
		program_terminate(program);
	}
	(void)os_key;
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

void	_clear(t_mlx_image *img)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_putpixel(img, x, y, 0x0);
			y++;
		}
		x++;
	}
}

void	program_run(t_program *program)
{
	if (mlx_image_to_window(program->mlx, program->buffer, 0, 0) == NULL)
		LOG_ERR("Unable to put image to window");
	else
		LOG("Put screen buffer to window");
	LOG("Drawing scene...");
	_clear(program->buffer);
	thread_init(program);
	LOG("Threads initialized");
	mlx_key_hook(program->mlx, (t_mlx_keyfunc)_mlx_keypress, program);
	LOG("ESC hook");
	LOG("Running mlx_loop");
	mlx_loop(program->mlx);
}

void	program_terminate(t_program *program)
{
	thread_terminate(program);
	mlx_delete_image(program->mlx, program->buffer);
	LOG("Freed screen buffer");
	mlx_terminate(program->mlx);
	LOG("Terminated MLX");
	ft_lstclear(&program->shapes, free);
	LOG("Freed shape list");
	ft_lstclear(&program->lights, free);
	LOG("Freed light list");
	free(program->shuffled);
}

t_program	program_get(void)
{
	t_program	program;

	ft_bzero(&program, sizeof(program));
	_init_mlx(&program);
	program.shuffled = shuffle(program.buffer->width * program.buffer->height);
	return (program);
}
