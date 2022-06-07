/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:11:40 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/07 10:10:16 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "log.h"

void	build_scene(t_program *program, char *file);

int	main(int argc, char **argv)
{
	t_program	program;

	program = program_get();
	if (argc < 2)
		argv[1] = "scenes/cylinder.rt";
	build_scene(&program, argv[1]);
	program.lights_amount = ft_lstsize(program.lights);
	program_run(&program);
	program_terminate(&program);
	LOG("Program end");
	return (EXIT_SUCCESS);
}
