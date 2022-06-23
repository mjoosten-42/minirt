/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:23:05 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/23 16:02:43 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "program.h"

void	thread_init(t_program *program)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&program->threads.mutex, NULL) < 0)
		rt_error(NULL, "Mutex allocation failed");
	while (i < NB_THREADS)
		pthread_create(&program->threads.threads[i++], NULL,
			(void *(*)(void *))scene_draw, program);
}

void	thread_terminate(t_program *program)
{
	int	i;

	i = 0;
	while (i < NB_THREADS)
		pthread_join(program->threads.threads[i++], NULL);
	pthread_mutex_destroy(&program->threads.mutex);
}
