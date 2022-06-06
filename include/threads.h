/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:21:55 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/06 14:26:15 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "program.h"
# include <pthread.h>

# define NB_THREADS 8

typedef struct s_program	t_program;

/**
**	Thread data
**	@param threads <pthread_t> Array of thread structs;
**	@param mutex <pthread_mutex_t> Mutex to select pixel to draw
*/
typedef struct s_threads
{
	pthread_t		threads[NB_THREADS];
	pthread_mutex_t	mutex;
}					t_threads;

void	thread_init(t_program *program);

#endif
