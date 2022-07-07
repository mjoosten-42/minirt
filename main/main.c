/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:11:40 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/07 11:26:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

clock_t	starttime;

int	main(int argc, char **argv)
{
	t_program	program;

	program = program_get();
	if (argc < 2)
		argv[1] = "scenes/maarten.rt"; // TODO: change
	build_scene(&program, argv[1]);
	program_init_mlx(&program);
	program_run(&program);
	program_terminate(&program);
	return (EXIT_SUCCESS);
}

__attribute__((constructor)) void start(void)
{
	starttime = clock();
}

__attribute__((destructor)) void end(void)
{
	clock_t	endtime;

	endtime = clock();
	printf("time elapsed: %lus\n", (endtime - starttime) / CLOCKS_PER_SEC);
}
