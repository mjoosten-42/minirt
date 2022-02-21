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

static t_program	*_allocate(void)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (program != NULL)
		ft_bzero(program, sizeof(t_program));
	return (program);
}

void	_init(t_program *program)
{
	program->mlx = mlx_init(WINDOW_W, WINDOW_H, WINDOW_TITLE, WINDOW_RESIZE);
	if (program->mlx == NULL)
		exit(EXIT_FAILURE);
	program->buffer = mlx_new_image(program->mlx, WINDOW_W, WINDOW_H);
	if (program->buffer == NULL)
		exit(EXIT_FAILURE);
	mlx_loop(program->mlx);
}

void	program_terminate(t_program *program)
{
	mlx_terminate(program->mlx);
	free(program);
}

t_program	*program_get(void)
{
	static t_program	*program = NULL;

	if (program == NULL)
	{
		program = _allocate();
		if (program != NULL)
			_init(program);
	}
	return (program);
}
