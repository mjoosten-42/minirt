/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   log.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 15:32:40 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 17:58:25 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "log.h"
#include <stdio.h>

void	log_msg(int line, const char *file, const char *func, const char *msg)
{
	printf("[%s:%d]<%s>: %s\n", file, line, func, msg);
}

void	log_err(int line, const char *file, const char *func, const char *msg)
{
	printf(ANSI_RED "[%s:%d]<%s>: %s\n" ANSI_RESET, file, line, func, msg);
}
