/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:23:05 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/09 15:58:21 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "program.h"
#include "log.h"

void	thread_init(t_program *program)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&program->threads.mutex, NULL) < 0)
	{
		LOG_ERR("Mutex allocation failed");
		exit(EXIT_FAILURE);
	}
	LOG("Created mutex");
	while (i < NB_THREADS)
		pthread_create(&program->threads.threads[i++], NULL,
			(void *(*)(void *))scene_draw, program);
	LOG("Created threads");
}

void	thread_terminate(t_program *program)
{
	int	i;

	i = 0;
	while (i < NB_THREADS)
		pthread_join(program->threads.threads[i++], NULL);
	LOG("Joined with threads");
	pthread_mutex_destroy(&program->threads.mutex);
	LOG("Destroyed mutex");
}
