/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program_init.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 15:43:29 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/04 15:21:21 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "log.h"
#include "shape.h"
#include "libft.h"
#include "MLX42/MLX42_Input.h"

void	_mlx_keypress(keys_t key)
{
	if (key == MLX_KEY_ESCAPE)
		exit(EXIT_SUCCESS);
}

void	_initmlx_t(t_program *program)
{
	program->mlx = mlx_init(WINDOW_W, WINDOW_H, WINDOW_TITLE, WINDOW_RESIZE);
	if (program->mlx == NULL)
		rt_error(NULL, "Failed to initialize MLX");
	program->buffer = mlx_new_image(program->mlx, WINDOW_W, WINDOW_H);
	if (program->buffer == NULL)
		rt_error(NULL, "Failed to initialize image");
}

void	program_run(t_program *program)
{
	if (mlx_image_to_window(program->mlx, program->buffer, 0, 0) < 0)
		rt_error(NULL, "Unable to put image to window");
	clear_screen(program->buffer);
	thread_init(program);
	mlx_key_hook(program->mlx, (mlx_keyfunc)_mlx_keypress, program);
	LOG("Running mlx_loop");
	mlx_loop(program->mlx);
}

void	program_terminate(t_program *program)
{
	thread_terminate(program);
	mlx_delete_image(program->mlx, program->buffer);
	mlx_terminate(program->mlx);
	ft_lstclear(&program->shapes, free);
	ft_lstclear(&program->lights, free);
	free(program->shuffled);
}

t_program	program_get(void)
{
	t_program	program;

	ft_bzero(&program, sizeof(t_program));
	_initmlx_t(&program);
	program.shuffled = shuffle(WINDOW_W * WINDOW_H);
	return (program);
}
