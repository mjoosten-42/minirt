/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 11:11:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 15:18:51 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

int	main(void)
{
	t_program	*program;

	program = program_get();
	if (program == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
