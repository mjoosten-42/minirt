/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:21:55 by mjoosten          #+#    #+#             */
/*   Updated: 2022/07/08 11:12:19 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "program.h"
# include <pthread.h>
# include "config.h"

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

struct	s_program;

void	thread_init(struct s_program *program);
void	thread_terminate(struct s_program *program);

#endif
