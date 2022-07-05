/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 11:11:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 15:56:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "log.h"

int	main(int argc, char **argv)
{
	t_program	program;

	program = program_get();
	if (argc < 2)
		argv[1] = "scenes/nick.rt"; // TODO: change
	build_scene(&program, argv[1]);
	program_init_mlx(&program);
	program_run(&program);
	program_terminate(&program);
	LOG("Program end");
	return (EXIT_SUCCESS);
}
